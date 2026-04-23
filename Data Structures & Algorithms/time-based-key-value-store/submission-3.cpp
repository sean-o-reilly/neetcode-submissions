class TimeMap {
public:
    TimeMap() = default;
    
    void set(string key, string value, int timestamp)
    {
        ht[key].insert_or_assign(timestamp, value);
    }
    
    string get(string key, int timestamp)
    {
        auto iter = ht[key].upper_bound(timestamp);
        return iter == ht[key].begin() ? "" : (--iter)->second;
        // if upper bound returns begin, we know the timestamp is less than all keys
        // if upper bound returns end or a valid node, 
        //      we can get the previous node and returns its value
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
