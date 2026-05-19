class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {
        if (arr.size() == 1 || arr.size() == k) return arr;

        if (x >= arr.back())
            return std::vector(arr.begin() + (arr.size() - k), arr.end());

        auto iter = std::lower_bound(arr.begin(), arr.end(), x);
        if (iter == arr.end()) throw std::invalid_argument("?");

        // true if a closer than b
        auto closerTo = [&x](int a, int b){
            return std::abs(a - x) < std::abs(b - x)
            || (std::abs(a - x) == std::abs(b - x) && a < b);
        };

        if (iter != arr.begin() && closerTo(*(iter - 1), *iter))
            --iter;

        // iter points to closest element <= x
        std::deque<int> res{*iter};

        auto left = iter;
        auto right = iter;
        --left;
        ++right;

        while (res.size() < k)
        {
            // both in bounds
            if (left >= arr.begin() && right != arr.end())
            {
                int a = *left;
                int b = *right;

                // if a closer
                if (closerTo(a, b))
                {
                    res.push_front(a);
                    --left;
                }
                else
                {
                    res.push_back(b);
                    ++right;
                }
            }
            else if (left >= arr.begin()) // no right side
            {
                res.push_front(*left);
                --left;
            }
            else if (right != arr.end()) // no left side
            {
                res.push_back(*right);
                ++right;
            }
        }

        return std::vector(res.begin(), res.end());
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