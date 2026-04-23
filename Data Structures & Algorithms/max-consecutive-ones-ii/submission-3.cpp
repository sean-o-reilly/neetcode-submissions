class Solution
{
public:

    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        if (nums.size() == 1) 
        {
            return 1;
        }

        int left = 0;
        int right = 0;
        
        int maxWidth = 0;

        bool hasZero = false;
        int lastOneIdx = 0;

        while (right < nums.size())
        {
            int curr = nums.at(right);

            if (curr == 1)
            {
                maxWidth = std::max(maxWidth, right - left + 1); // include right
            }
            else
            {
                if (hasZero)  // reset window on second 0 found
                {
                    left = right;
                    hasZero = false;
                }
                else
                {
                    maxWidth = std::max(maxWidth, right - left + 1);
                    hasZero = true;
                }
            }

            ++right;
        }

        return maxWidth;
    }
};

/*

01
1001

101011000

*/