#include <utility>

class Solution
{
public:
    int tribonacci(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        else if (n < 3)
        {
            return 1;
        }

        int prev0 = 0; // T0
        int prev1 = 1; // T1
        int prev2 = 1; // T2

        int res = 0;
        
        for (int i = 3; i <= n; ++i)
        {
            res = prev0 + prev1 + prev2;

            // give res's value to prev2, prev2's value to prev1, and prev1's value to prev0
            prev0 = std::exchange(prev1, std::exchange(prev2, res));
        }

        return res;
    }
};