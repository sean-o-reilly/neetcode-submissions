class Solution {
public:
    int hammingWeight(uint32_t n) 
    {   
        int count = 0;

        while (n > 0)
        {
            uint32_t bit  = n & 0b1;
            if (bit == 0b1) ++count;
            n = n >> 1;
        }

        return count;
    }
};

/*

we can get the LSB by taking the AND with 0b1
then after that, we can right shift it to move the numbers down and count more

10111
take & 1 -> 1, increment a count variable
shift right
1011
++
101
++
10
1
++
0. stop when n == 0

11111111101
& 1 == 1, ++
1111111110 & 1 == 0
111111111...

*/