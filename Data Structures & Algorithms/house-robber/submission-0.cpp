#include <utility>

class Solution {
public:

    int rob(vector<int>& nums) 
    {
        int prev1 = 0;
        int prev2 = 0;

        for (int num : nums)
        {
            prev2 = std::exchange(prev1, std::max(prev2 + num, prev1));
        }

        return prev1; // how the hell does this work
    }
};

/*

Decision tree
For each house
    if we robbed previous house, skip

    if not, choose to 
        Rob or not rob

    generate all possible paths and take the max

    O(2^n) time complexity

    cache?

    

*/