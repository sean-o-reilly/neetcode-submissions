class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        const int bits = 32;

        uint32_t res = 0;

        for (int i = 0; i < bits; ++i)
        {
            uint32_t bit = ((n >> i) & 1);
            res = ((res << 1) | bit);
        }

        return res;
    }
};

/*
1 = 0000 0001

0000 1010
>> 0000 1010 & 1 = 0
>> 0000 0101 & 1 = 1
>> 0000 0010 & 1 = 0
>> 0000 0001 & 1 = 1
>> 0000 0000 & 1 = 0
...
these can be add to our res ^

res 
0000 0000, left shift 0 by 1, or it with 0
0000 0001, left shift 0 by 1, or it with 1
0000 0010, left shift 0001 by 1, or it with 0
0000 0101, left shift 0010 by 1, or it with 1
...

res = 0101 0000

*/