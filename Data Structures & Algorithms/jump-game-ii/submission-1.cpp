class Solution {
public:

    int jump(vector<int>& nums)
    {
        int left = 0;
        int right = 0;
        int jumps = 0;

        while (right < nums.size() - 1)
        {
            int farthest = 0;

            for (int i = left; i <= right; ++i)
            {
                farthest = std::max(farthest, i + nums.at(i));
            }

            left = right + 1;
            right = farthest;
            jumps++;
        }

        return jumps;
    }
};

/*

Decision tree recursive approach

Needs to be optimized with memoization

Per index:
    Try max amount of jumps, then max -1, max -2...


globalMin

void recursive(nums, currIdx, numJumps):
    if currIdx >= nums.size() - 1
        // past end of array
        globalMin = min(globalMin, numJumps)

    for (int i = nums.at(currIdx); i > 0; --i)
        recursive(nums, currIdx + i, numJumps + 1) // jump


call as

recrusive(nums, 0, 0)

*/
