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

        int prev0 = 0;
        int prev1 = 1;
        int prev2 = 1;

        int res = 0;
        
        for (int i = 3; i <= n; ++i)
        {
            std::cout << prev0 << " " << prev1 << " " << prev2 << std::endl;
            res = prev0 + prev1 + prev2;

            prev0 = std::exchange(prev1, std::exchange(prev2, res));
        }

        return res;
    }
};