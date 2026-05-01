class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        auto it = std::partition(nums.begin(), nums.end(),
                            [val](int x) { return x != val; });

        return std::distance(nums.begin(), it);
    }
};
