#include <ranges>

class Solution {
public:

    void recurse(int i, const std::vector<int> combo, int target, std::vector<int>& nums, std::vector<std::vector<int>>& res)
    {
        auto sum = std::accumulate(combo.begin(), combo.end(), 0);

        if (sum == target)
        {
            res.push_back(combo);
        }
        else if (sum < target)
        {
            auto newCombo = combo;
            newCombo.push_back(nums.at(i));
            recurse(i, newCombo, target, nums, res);

            i += 1;
            if (i < nums.size())
            {
                recurse(i, combo, target, nums, res);
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target)
    {
        std::vector<std::vector<int>> res;
        recurse(0, {}, target, nums, res);
        return res;
    }
};

/*

i = 0

recurse(i, &nums, combo):

    if sum(combo) == target
        nums.push combo

    if sum < target
        recurse(i, nums, combo + nums.at(i))

    i += 1
    if i < nums.size()
        for (int j = i ...)
            recurse(j, nums, combo)





decide:
either 
    choose number (first of list, i)
    append number to rolling combo
    continue with same subset, i stays the same
or 
    pop number from front
    continue with new subset (i + 1)

*/