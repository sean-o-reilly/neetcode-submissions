class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int curr = 0;
        for (int num : nums) curr = curr ^ num;
        return curr;
    }
};

/*
O(nlogn)
    Sort list and traverse in pairs somehow
    [1, 1, 2, 2, 3, 3, 4, 5, 5]

    4 breaks the pair, return 4

O(n) time and space
    Use a hashmap.
        Number : count of number in nums
    
    Traverse hashmap, return key who's value is 1

    Or

    Use a hash set (unordered)
        For each number,
            if the number is NOT in the set, add it to set
            if the number IS IN the set, remove it from the set

        return last remaining number. (if size != 1, error!)

    More space efficient on best case scenarios like [1, 1, 2, 2, 3, 3, 4]

Bit manipulation
O(n) time, O(1) space

Hint: Use XOR

When two identical numbers are XORd, they result in 0

[3, 2, 3]

start with 3, 0011, xor with next number, 2
 0011
^0010 = 0001

0001, xor with next number, 3 0011

0001
0011
0010 = 2, identical number

[7, 6, 6, 7, 8]

1110
0110 -> 1000
0110 -> 1110
1110 -> 0000
1000 -> 1000 = 8

curr = 0000

for number in array
    curr = curr ^ number

*/