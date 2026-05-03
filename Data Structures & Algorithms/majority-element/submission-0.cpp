class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        std::unordered_map<int, int> count;
        for (const auto num : nums)
            count[num]++;
        
        for (const auto [k, v] : count)
        {
            if (v > nums.size() / 2)
            {
                return k;
            }
        }

        return -1;
    }
};