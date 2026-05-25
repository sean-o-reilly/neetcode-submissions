class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right)        
        {
            int sum = numbers.at(left) + numbers.at(right);
            if (sum > target) {
                --right;
            }
            else if (sum < target) {
                ++left;
            }
            else {
                return std::vector{left + 1, right + 1};
            }
        }

        throw std::logic_error("no solution?");
    }
};

/*
non dec order

[1, 2, 3, 4] target = 3

[1, 2] sum = 3

O(1) space
two pointer
left and right start at index 0 and end - 1
move right down while sum > target
move left up while sum < target


[1, 2, 3, 4, 9] target = 7
[-999, -1, 1000, 9999] target = 999
[1, 2, 3, 4, 5] target = 9
[1, 1] target = 2



O(n) space
hashmap     target - seen, index
(whatever number is the complement, to add up to the sum, track whether or not it was previously seen)
for each number
    number in hasmap,
        return hashmap[number], curr index
    else add target - number, index to hashmap

*/