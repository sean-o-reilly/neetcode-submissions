class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {
        int left = 0;
        int right = arr.size() - 1;
        int mid = (right + left) / 2;

        while (left < right)
        {
            if (arr.at(mid) == x)
            {
                break;
            }
            else if (arr.at(mid) < x)
            {
                left = mid + 1;
            }
            else if (arr.at(mid) > x) 
            {
                right = mid - 1;
            }
            mid = (right + left) / 2;
        }

        // mid -> first element <= x
        if (arr.at(mid) > x && mid > 0)
            --mid;
        std::cerr << arr.at(mid) << std::endl;

        left = mid;
        right = mid + 1;
        while (right - left - 1 < k)
        {
            if (left < 0)
            {
                ++right;
            }
            else if (right >= arr.size())
            {
                --left;
            }
            else if (std::abs(arr.at(left) - x) < std::abs(arr.at(right) - x)
            || (std::abs(arr.at(left) - x) == std::abs(arr.at(right) - x) && arr.at(left) < arr.at(right)))
            {
                std::cerr << " a < b" << std::endl;
                --left;
            }
            else
            {
                ++right;
            }
        }

        return std::vector(arr.begin() + left + 1, arr.begin() + right);
    }
};

/*

diff a and x = |a - x|
prioritize smaller values on a tie

binary search
    lookup x

[1, 2, 3, 4, 5, 6, 7, 8 ,9], k = 3, x = 5


binary search to closest number <= x
two pointer approach from either side of x

[1, 2, 3, 10, 12, 13]
lookup 5
find closest is 3
take 3
need k more elements
two pointer
    compare left (a) to right (b) while (res[] < k)
        * make sure to bounds check left and right here
        
        if diff of left is <= diff of right
            take left
            --left
        else
            take 
            ++right
    
[1, 5, 6, 7, 8, 9]
[-999999, 2, 5, 7, 999]

*/