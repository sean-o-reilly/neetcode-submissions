class Solution {
public:
    int findMin(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums.at(0);
        }

        int left = 0;
        int right = nums.size() - 1;
        int middle;
        int min = std::numeric_limits<int>::max();

        while (left <= right)
        {
            middle = (left + right) / 2;

            if (nums.at(left) < nums.at(right))
            {
                return std::min(min, nums.at(left));
            }
            else if (nums.at(middle) >= nums.at(left))
            {
                left = middle + 1;
            }
            else if (nums.at(middle) < nums.at(left))
            {
                right = middle - 1;
            }

            min = std::min(min, nums.at(middle));
        }

        return min;
    }
};

/*
pseudocode:

int findMin(nums):
    int left = 0
    int right = nums size - 1
    int middle
    int min = INF

    while (left < right)
        middle = (left + right) / 2

        if (left num < right num) // fully sorted
            return min of min, left num
        
        else if middle num >= left num // move to less segment
            mid = mid + 1
            update min
        else if middle num < left num
            // already in lesser segment
            update min


middle >= left, meaning middle is in the greater segment
if middle < left, middle is in the lesser segment

if left < right, middle is in a fully sorted segment, and know the left pointer is the smallest
of the segment

[5, 6, 7, 8, 2, 3, 4]





[3,4,5,6,1,2]
[3,4,5,6] [1,2]
[6,1,2]
[1,2]
fully sorted

[4,5,0,1,2,3]
0 < 4
[1,2,3]
fully sorted
return min of current min and leftmost

[4,5,6,7]
fully sorted, return min


*/
