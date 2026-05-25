class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int left = 0;
        int right = 1;
        int k = 1;

        while (right < nums.size())     
        {
            if (nums.at(right) != nums.at(right - 1))
            {
                ++left;
                ++k;
                nums.at(left) = nums.at(right);
                ++right;
            }
            else
            {
                ++right;
            }
        }

        return k;
    }
};

/*
[1,1,2,3,4]
unique if element before is less than
left = 0, right = 1
    right not unique, ++right
left = 0, right = 2
    right unique
    ++left
    at(left) = at(right)
    ++right
left = 1, right = 3
    right unique
    ++left
    at left = at right
    ++ right
left = 2, right = 4
    right unique
    at left 


*/