#include <ranges>

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        auto zeroes = std::ranges::count(nums, 0);
        
        if (zeroes >= 2)
        {
            return std::vector(nums.size(), 0);
        }
        else if (zeroes == 1)
        {
            int index = std::distance(nums.begin(), std::ranges::find(nums, 0));
            nums.at(index) = 1;
            std::vector<int> res(nums.size(), 0);
            res.at(index) = std::ranges::fold_left(nums, 1, std::multiplies{});
            return res;
        }

        int productSum = std::ranges::fold_left(nums, 1, std::multiplies{});

        std::vector<int> res(nums.size());
        std::transform(nums.begin(), nums.end(), res.begin(), [=](int x){return productSum / x;});
        return res;        
    }
};
