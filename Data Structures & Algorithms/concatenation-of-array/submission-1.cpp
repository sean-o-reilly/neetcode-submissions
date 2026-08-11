class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums)
    {
        nums.insert(nums.end(), nums.cbegin(), nums.cend());
        return nums;
    }
};