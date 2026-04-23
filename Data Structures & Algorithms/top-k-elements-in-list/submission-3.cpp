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
            return a.first > b.first;
        };
        std::priority_queue<Pair, std::vector<Pair>, decltype(cmp)> pq;

        for (auto [num, count] : hm)
        {
            if (pq.size() < k)
            {
                pq.push({count, num});
            }
            else if (count > pq.top().first)
            {
                pq.push({count, num});
                pq.pop();
            }
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
