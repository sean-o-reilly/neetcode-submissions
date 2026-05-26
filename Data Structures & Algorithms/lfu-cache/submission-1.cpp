class LFUCache
{
public:

    struct Data
    {
        int key;
        int value;
        int freq;
    };

    using LRUList = std::list<std::shared_ptr<Data>>;
    using LFUList = std::list<std::shared_ptr<Data>>;

    struct KeyData
    {
        std::shared_ptr<Data> data;
        LRUList::iterator lRecNode;
        LFUList::iterator lFreqNode;
    };

    LFUCache(int capacity)
    : capacity_{capacity}
    {
    }
    
    int get(int key)
    {
        if (!mainMap_.contains(key))
        {
            return -1;
        }

        KeyData& kData = mainMap_.at(key);
        incrementFreq(kData);
        return kData.data->value;
    }

    void incrementFreq(KeyData& kData)
    {
        // remove from current frequency list
        LFUList& lfuList = freqMap_.at(kData.data->freq);
        lfuList.erase(kData.lFreqNode);
        if (lfuList.empty()) freqMap_.erase(kData.data->freq); // erase empty list
        kData.data->freq++;

        // add to higher frequency list 
        LFUList& newList = freqMap_[kData.data->freq];
        newList.push_front(kData.data);
        kData.lFreqNode = newList.begin();

        // update LRU ordering
        lruList.splice(lruList.end(), lruList, kData.lRecNode);
    }
    
    void put(int key, int value)
    {
        handleEviction();

        if (mainMap_.contains(key)) // overrite
        {
            KeyData& kData = mainMap_.at(key);
            kData.data->value = value;
            incrementFreq(kData);
        }
        else
        {
            KeyData& kData = mainMap_[key];

            // create a data instance to be shared among 3 data structures
            kData.data = std::make_shared<Data>(key, value, 1);

            lruList.push_back(kData.data);
            kData.lRecNode = std::prev(lruList.end(), 1);

            freqMap_[1].push_front(kData.data);
            kData.lFreqNode = freqMap_.at(1).begin();
        }
    }

    void handleEviction()
    {
        if (mainMap_.size() >= capacity_)
        {
            auto [minFreq, lfuList] = *std::min_element(
                freqMap_.begin(),
                freqMap_.end(),
                [](const auto& a, const auto& b) {
                    return a.first < b.first;
                }
            );

            if (lfuList.empty()) throw std::logic_error("stale empty lfu list");

            if (lfuList.size() == 1)
            {
                evict(lfuList.front()->key);
                if (freqMap_.contains(minFreq)) throw std::logic_error("stale list not removed");
            }
            else
            {
                auto lruIter = std::find_if(lruList.begin(), lruList.end(), [&](const auto& data){
                    return data->freq == minFreq;
                });

                std::shared_ptr<Data> data = *lruIter;
                evict(data->key);
            }
        }
    }

    void evict(int key)
    {
        KeyData& kData = mainMap_.at(key);

        // remove from LFU
        int freq = kData.data->freq;
        LFUList& lfuList = freqMap_.at(freq);
        lfuList.erase(kData.lFreqNode);
        if (lfuList.empty()) freqMap_.erase(freq); // remove empty lists

        // remove from LRU
        lruList.erase(kData.lRecNode);

        // remove from main
        mainMap_.erase(key);
    }

private:
    int capacity_;

    std::unordered_map<int, KeyData> mainMap_;
    std::unordered_map<int, LFUList> freqMap_;
    LRUList lruList;
};

/*
LRU ordering
    hashmap + linked list

    key -> Node{key, value, freq}

LFU ordering
    hashmap (count -> linked list)

    count/freq -> {linked list of Node{key, val, freq} }

Lookup (get or put)
    key -> {LRU node, LFU node}

    splice LRU node to back

    access LFU node, its frequency is known
        remove from its list
        increment frequency
        reinsert at LFU map.at(frequency)

Eviction (after put, size > capacity)
    find min key in freq map

    if there is one key at the min level,
        evict that key
    if there is two keys
        lookup all key's LRU ordering
        evict whichever one has less distance from begin O(n) on a tie

evictNode(key):
    LRUNode, LFUNode = keyMap.at(key)

    LRUlist.erase(LRUNode)
    LFUlist.at(freq).erase(LFUNode)

evictLFU():
    [minFreq, minLevel] = findMinKey(freq map)

    if minLevel.size() == 1
        key = minlevel.at(0).key
        evictNode(key)
    else
        // evict first key in LRU with min frequency
        // scan from old to new
        for node in LRUlist:
            if node frequency == min
                LRUlist.erase(node)
                return

    

Min tracking

    linear search over hashmap for min key, only needed on eviction
        would still be amortized O(1) since most operations do 
        not cause an eviction. would be bad at full cache size though

        or worst case O(m) where m is the number of unique frequencies


*/