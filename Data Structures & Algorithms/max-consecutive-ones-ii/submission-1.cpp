class Solution {
public:
    int findMax(vector<int>& nums)
    {
        int max = 0;
        int streak = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums.at(i) == 1)
            {
                ++streak;
                max = std::max(max, streak);
            }
            else
            {
                max = std::max(max, streak);
                streak = 0;
            }
        }    

        return max;
    }

    int tryFlip(std::vector<int>& nums, int idx)
    {
        int original = nums.at(idx);

        nums.at(idx) = 1;

        int res = findMax(nums);

        nums.at(idx) = original;

        return res;
    }

    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int max = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            max = std::max(max, tryFlip(nums, i));
        }

        return max;
    }
};

/*

10101100011101

*/