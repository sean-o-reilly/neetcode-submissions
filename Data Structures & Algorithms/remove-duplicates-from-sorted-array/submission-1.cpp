class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int write = 0;
        int read = 1;
        int k = 1;

        while (read < nums.size())
        {
            if (nums.at(read - 1) != nums.at(read))
            {
                ++write; // "append" to unique segment
                nums.at(write) = nums.at(read); // add new value
                ++read;
                ++k;
            }
            else
            {
                ++read; // search for new unique value
            }
        }

        return k;
    }
};

/*
*/