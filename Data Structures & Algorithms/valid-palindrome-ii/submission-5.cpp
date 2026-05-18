class Solution {
public:
    bool validPalindrome(string s)
    {
        const int n = s.length();

        int left = 0;
        int right = n - 1;

        auto isPalindrome = [&s](int left, int right){
            while (left < right)
            {
                if (s.at(left) != s.at(right))
                    return false;
                ++left;
                --right;
            }
            return true;
        };

        while (left < right)
        {
            if (s.at(left) != s.at(right))
            {
                return (isPalindrome(left + 1, right) || isPalindrome(left, right - 1));
            }

            ++left;
            --right;
        }

        return true;
    }
};