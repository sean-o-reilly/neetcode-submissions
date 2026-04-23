class Solution {
public:
    double powRecursive(double x, int n)
    {
        if (n == 0) return 1.0;
        if (n == 1) return x;

        double subNumber = powRecursive(x, n / 2);
        double res = subNumber * subNumber;

        if (n % 2 != 0) // exponent was odd, multiply by constant
        {
            res *= x;
        }

        return res;
    }

    double myPow(double x, int n)
    {
        double res = powRecursive(x, n);

        if (n < 0)
        {
            res = 1 / res;
        }

        return res;
    }
};
