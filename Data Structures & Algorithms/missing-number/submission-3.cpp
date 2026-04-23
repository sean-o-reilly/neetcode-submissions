class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int mask = 0;
        for (auto num : nums)
        {
            mask = mask ^ num;
        }

        int fullmask = 0;
        for (int i = 0; i <= nums.size(); ++i)
        {
            fullmask = fullmask ^ i;
        }

        std::cout << mask << " " << fullmask << std::endl;

        return mask ^ fullmask;
    }
};

/*
Bit manip

0 XOR 1 XOR 2 XOR 3 = 0
1 XOR 2 XOR 3 = 0
0 XOR 0 = 0 !!

0 XOR 1 XOR 2 = 3
0 XOR 2 = 2
3 XOR 2 = 1 !!

*/