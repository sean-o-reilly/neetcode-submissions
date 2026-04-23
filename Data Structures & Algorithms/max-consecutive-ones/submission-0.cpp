class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
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
};