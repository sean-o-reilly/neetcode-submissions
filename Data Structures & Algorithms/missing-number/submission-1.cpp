class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i)
        {
            if (missing == nums[i])
            {
                ++missing;
            }   
            else {break;}
        }

        return missing;
    }
};

