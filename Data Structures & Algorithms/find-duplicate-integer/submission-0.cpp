class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        std::unordered_set<int> seen;
        for (int num : nums) 
        {
            if (seen.count(num))
            {
                return num;
            }
            else
            {
                seen.insert(num);
            }
        }

        throw std::runtime_error("No duplicate found?");
    }
};
