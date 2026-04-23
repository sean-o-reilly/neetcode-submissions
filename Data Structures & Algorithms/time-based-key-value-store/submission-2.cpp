class TimeMap {
public:
    TimeMap() = default;
    
    void set(string key, string value, int timestamp)
    {
        ht[key].insert_or_assign(timestamp, value);
    }
    
    string get(string key, int timestamp)
    {
        if (ht.count(key))
        {
            std::map<int, std::string>& timemap = ht[key];

            if (timemap.count(timestamp))
            {
                return timemap[timestamp];
            }
            else
            {
                // only keep search if a previous relevant timestamp is in the map
                auto leftMost = *(timemap.begin());
                if (timestamp > leftMost.first)
                {
                    auto iter = timemap.upper_bound(timestamp);
                    if (--iter != timemap.end()) // --iter is the first element less than timestamp
                    {
                        return (*iter).second; // return value of first element less than timestamp
                    }
                }
            }
        }

        return "";
    }

private:
    std::unordered_map<std::string, std::map<int, std::string>> ht;
};


/*

Storage:
    Hashmap: string/key->Treemap
        Treemap: timestamp->value
            Treemap/std::map is ordered and supports iterators
                We are able to walk back/forward in the tree
                from a given iterator


timestamps:
1 - 5 - 7

get key with timetsamp 6
    6 is not in timestamps
    but 6 is less than 7, so there is some relevant timestamps, either 1 or 5

    get upper bound of 6, then walk back one to the first element less than 6

*/
