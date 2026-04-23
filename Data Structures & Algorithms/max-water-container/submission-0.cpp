class Solution {
public:
    int maxArea(vector<int>& heights)
    {
        int left = 0; 
        int right = heights.size() - 1;
        int max = 0;

        while (left < right)
        {
            int currWater = (right - left) * std::min(heights[left], heights[right]);

            if (heights[right] <= heights[left]) // move right if tied
            {
                --right;
            }
            else
            {
                ++left;
            }

            max = std::max(max, currWater);
        }

        return max;
    }
};


/*

Container of heights
Each index's value represents a height value

return the max amount of water a container can store

this would amount to the area of the distance between indices to the min on their heights


9 4 4 8 3

Choose 9 and 8,
    width = 3 apart (index 3 - index 0)
    height = min of 9 and 8

    water = width * height

Brute force:

    For each i, check against j index what the width*height would be. Track a max for the
    whole array. This would be a O(n^2) solution

More optimal:

    Using a left and right index, 2 pointer approach

    [1,7,2,5,4,7,3,6]

    Left tower = first
    Right tower = second
    Max is 0

    Starting water would be 1*1, greater than our max of zero
    Since its greather, move right to the right
    Left = first 
    Right = third (2)
    Current water is now 2 * 1
    Greater than max so increment right
    1 and 5
    3*1, greater than max
    1 and 4
    1*4 greater than max
    1 and 7(right)
    1*5, greater tha nmax
    1*3, less than max
    move left 
    7 and 3
    5 * 3 = 15 greater than max
    7 and 6
    6 * 6 = 36 greater than max
    Move right again
    Right past end of array, done

    Compute current water with two given towers, Move the pointer with the smaller height value?

        Do this until right (left?) reaches the end. Make sure right always greater than left 
        when moving left, but right doesn't go past the end

    

    [9 4 4 8 3]

    [5, 4, 3, 2, 1]
    [1, 2, 3, 4, 5]

    [3, 5, 2, 2, 5, 6, 9, 5, 3, 3]

Edge cases:


*/
