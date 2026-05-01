class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int k = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums.at(i) != val)
            {
                nums.at(k++) = nums.at(i);
            }
        }

        return k;
    }
};

/*
traverse array

index i is current element

if i is the val we need to erase,
    find an index j where j is a non-val number

once j is found, swap i and j. then increment some count variable

[1, 1, 2, 3, 4]
1, 1, 2, 3, 4
    k = 5
2, 1, 1, 3, 4
    k = 4


*/