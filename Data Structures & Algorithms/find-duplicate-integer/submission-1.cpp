class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            int num = std::abs(nums[i]);

            if (nums[num] < 0) // number already seen
            {
                return num;
            }
            else // mark index abs nums[i] as seen
            {
                nums[num] *= -1;
            }
        }

        throw std::runtime_error("No duplicate found?");
    }
};


/*

Some way to use positive values only, and use the array itself as a hash

*/