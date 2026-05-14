class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    { 
        std::vector<std::unordered_set<int>> buckets(nums.size() + 1);
        std::unordered_map<int, int> hm;

        for (auto num : nums)
        {
            hm[num]++;
        }

        for (auto [k, v] : hm)
        {
            buckets.at(v).insert(k);
        }

        std::vector<int> res;

        for (int i = buckets.size() - 1; i >= 0; --i)
        {
            auto& bucket = buckets.at(i);
            for (auto num : bucket)
            {
                res.push_back(num);
                if (res.size() == k)
                    return res;
            }
        }

        throw std::logic_error("not enough top nums?");
    }
};


/*
bucket sort
[1, 2, 2, 3, 3, 3]
        [{}, {1}, {2}, {3}, {}, {}, {}]
times = 0    1    2   3  4   5    6

       [{}, {}, {7}, {}, {}, {}, {}, {}]
times =  0   1   2   3   4   5  6    7

*/
