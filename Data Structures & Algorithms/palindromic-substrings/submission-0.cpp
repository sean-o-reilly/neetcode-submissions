class Solution {
public:
    bool isPalindrome(std::string s)
    {
        int left = 0;
        int right = s.size() - 1;

        while (left < right)
        {
            if (s[left] != s[right])
            {
                return false;
            }

            ++left;
            --right;
        }

        return true;
    }

    int countSubstrings(std::string s)
    {
        int count = 0;

        for (int width = 1; width <= s.size(); ++width)
        {
            for (int i = 0; i < s.size(); ++i)
            {
                if (i + width > s.size()) continue;
                
                std::string subString;

                for (int j = i; j < i + width; ++j)
                {
                    subString += s[j];
                }

                std::cout << subString << std::endl;

                count += isPalindrome(subString);
            }
        }

        return count;
    }
};
