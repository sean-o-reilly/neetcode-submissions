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
        int count = s.size();

        for (int width = 2; width <= s.size(); ++width)
        {
            for (int i = 0; i < s.size(); ++i)
            {
                if (i + width > s.size()) continue;
                
                std::string subString = s.substr(i, width);

                std::cout << subString << std::endl;

                count += isPalindrome(subString);
            }
        }

        return count;
    }
};
