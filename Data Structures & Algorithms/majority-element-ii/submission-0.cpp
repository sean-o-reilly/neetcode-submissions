class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        std::unordered_map<int, int> counts;
        for (const auto num : nums)
            counts[num]++;

        std::vector<int> res;
        for (const auto [k, v] : counts)
        {
            if (v > nums.size() / 3)
            {
                res.push_back(k);
            }
        }

        return res;
    }
};