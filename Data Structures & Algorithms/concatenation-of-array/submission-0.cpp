class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        const int sz = nums.size();
        nums.reserve(sz * 2);

        for (int i = 0; i < sz; ++i)
        {
            nums.push_back(nums.at(i));
        }

        return nums;
    }
};