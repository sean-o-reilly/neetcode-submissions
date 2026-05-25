class MyHashMap {
public:
    MyHashMap() : buckets_(10)
    {
    }
    
    void put(int key, int value)
    {
        std::cerr << "put " << key << ", " << value << std::endl;
        auto& bucket = buckets_.at(index_(key));
        auto iter = std::ranges::find_if(bucket, [&](const auto& p){return p.first == key;});

        if (iter == bucket.end())
        {
            bucket.emplace_front(key, value);
            ++size_;
            handleResize_();
        }
        else
        {
            iter->second = value; // overwrite
        }
    }
    
    int get(int key) const
    {
        std::cerr << "get " << key << std::endl;

        auto& bucket = buckets_.at(index_(key));
        for (const auto& [k, val] : bucket)
        {
            if (k == key)
                return val;
        }

        return -1;
    }
    
    void remove(int key)
    {
        std::cerr << "remove " << key << std::endl;
        auto& bucket = buckets_.at(index_(key));
        
        for (auto iter = bucket.begin(); iter != bucket.end(); ++iter)
        {
            if (iter->first == key)
            {
                bucket.erase(iter);
                return;
            }
        }
    }

private:
    using Table = std::vector<std::list<std::pair<int, int>>>;
    Table buckets_;
    Table::size_type size_;
    std::hash<int> hash_;

    void handleResize_()
    {
        constexpr float loadFactor = 0.5;
        if (1.0 * size_ / (1.0 * buckets_.size()) > loadFactor)
        {
            std::cerr << "resizing: " << size_ << " / " << buckets_.size() << std::endl;
            Table newTable(buckets_.size() * 2);

            for (const auto& bucket : buckets_)
            {
                for (const auto& [k, v] : bucket)
                {
                    newTable.at(hash_(k) % newTable.size()).emplace_front(k, v);
                }
            }

            buckets_ = newTable;
        }
    }

    Table::size_type index_(int key) const
    {
        return hash_(key) % buckets_.size();
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */