class Solution {
public:
    double myPow(double x, int n)
    {
        if (n == 0) return 1;

        double base = x;

        for (int i = 1; i < std::abs(n); ++i)
        {
            x *= base;
        }

        if (n < 0)
        {
            x = 1 / x;
        }

        return x;
    }
};
