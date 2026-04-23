class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        std::unordered_map<int, int> hm; // number -> count
        hm.reserve(nums.size());

        for (auto num : nums)
        {
            hm[num]++;
        }

        using Pair = std::pair<int, int>; // count, number
        auto cmp = [](Pair& a, Pair& b)
        {
            return a.first < b.first;
        };

        std::priority_queue<Pair, std::vector<Pair>, decltype(cmp)> pq;

        for (auto [key, v] : hm)
        {
            pq.push({v, key});
        }

        std::vector<int> res;

        for (int i = 0; i < k; ++i)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
