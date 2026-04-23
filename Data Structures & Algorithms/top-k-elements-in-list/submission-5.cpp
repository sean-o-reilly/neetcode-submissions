class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    { // bucket sort with hints
        std::unordered_map<int, int> hm; // number -> count
        hm.reserve(nums.size());
        for (auto num : nums)
            hm[num]++;

        std::vector<std::vector<int>> buckets(nums.size());

        for (auto [num, count] : hm)
        {
            buckets.at(count - 1).push_back(num);
        }

        std::vector<int> res;
    
        for (int i = buckets.size() - 1; i >= 0; --i)
        {
            std::vector<int>& bucket = buckets.at(i);
            for (auto num : bucket)
            {
                res.push_back(num);
                
                if (res.size() == k)
                    return res;
            }
        }

        return res;
    }
};
