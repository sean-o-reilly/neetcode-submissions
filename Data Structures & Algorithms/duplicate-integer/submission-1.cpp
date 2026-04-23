class Solution {
public:
    bool hasDuplicate(vector<int>& nums)
    {
        std::unordered_set<int> seen;
        for (const int num : nums)
        {
            if (seen.count(num)) return true;
            else seen.insert(num);
        } 

        return false;
    }
};