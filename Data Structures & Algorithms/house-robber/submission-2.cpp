#include <utility>

class Solution {
public:

    int rob(vector<int>& nums) 
    {
        int prev1 = 0;
        int prev2 = 0;

        for (int num : nums)
        {
            int curr = std::max(prev2 + num, prev1);
            prev2 = std::exchange(prev1, curr);
        }

        return prev1;
    }
};
