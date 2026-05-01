class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int k = nums.size();

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums.at(i) == val)
            {
                for (int j = i + 1; j < nums.size(); ++j)
                {
                    if (nums.at(j) != val)
                    {
                        std::swap(nums.at(i), nums.at(j));
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums.at(i) == val)
            {
                k = i;
                break;
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