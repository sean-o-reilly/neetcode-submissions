class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto iter = std::lower_bound(nums.begin(), nums.end(), target);
        if (iter == nums.end()) return nums.size();
        // if (*iter >= target)
        return std::distance(nums.begin(), iter);
    }
};