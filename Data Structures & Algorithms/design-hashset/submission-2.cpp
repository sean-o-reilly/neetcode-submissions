class MyHashSet {
public:
    MyHashSet()
    : size_{0}, capacity_{10}, buckets(capacity_)
    {
    }
    
    void add(int key)
    {
        if (contains(key)) return;

        if (size_ / (double)capacity_ > maxLoad_)
        {
            resize();
        }

        buckets.at(lookupIndex(key)).push_front(key);
        ++size_;
    }
    
    void remove(int key) 
    {
        std::list<int>& bucket = buckets.at(lookupIndex(key));

        auto iter = std::find(bucket.begin(), bucket.end(), key);

        if (iter != bucket.end())
        {
            bucket.erase(iter);
            std::cout << "removed " << key << std::endl;
            --size_;
        }
        else
        {
            std::cout << key << " could not remove, not in list" << std::endl;
        }
    }
    
    bool contains(int key) const
    {
        const std::list<int>& bucket = buckets.at(lookupIndex(key));

        const auto iter = std::find(bucket.begin(), bucket.end(), key);

        if (iter != bucket.end())
        {
            std::cout << "Found " << key << std::endl;
        }

        return iter != bucket.end();
    }

private:

    void resize()
    {
        // capacity_ *= 2;
        std::vector<std::list<int>> newBuckets(capacity_);
        // newBuckets.reserve(capacity_);

        for (const std::list<int>& bucket : buckets)
        {
            for (int element : bucket)
            {
                // newBuckets.at(lookupIndex(element)).push_front(element);
            }
        }

        // buckets = std::move(newBuckets);
        // buckets.clear();
        // buckets = newBuckets;
    }

    std::size_t lookupIndex(int key) const
    {
        // std::cout << "Index of " << key << " is " << std::hash<int>{}(key) % capacity_ << std::endl;
        return std::hash<int>{}(key) % capacity_;
    }

    static constexpr double maxLoad_ = 0.5;

    std::vector<std::list<int>> buckets;
    std::size_t size_;
    std::size_t capacity_;

};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */