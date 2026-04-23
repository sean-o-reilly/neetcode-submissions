class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int low = 0;
        int high = nums.size() - 1;

        int mid;

        while (high >= low)
        {
            mid = (high + low) / 2;
            int curr = nums[mid];

            if (curr == target)
            {
                return mid;
            }
            else if (target > curr) // move up
            {
                low = mid + 1;
            }
            else if (target < curr) // move down
            {
                high = mid - 1;
            }
        }

        return -1;
    }
};
