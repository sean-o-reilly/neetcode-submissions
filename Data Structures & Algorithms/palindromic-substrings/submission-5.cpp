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

        for (int center = 0; center < s.size(); ++center)
        {
            int left = center;
            int right = center;

            std::cout << center << ":\n";

            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                std::cout << s.substr(left, right - left + 1) << std::endl;
                ++count;
                --left;
                ++right;
            }

            // even case
            
            left = center;
            right = center + 1;

            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                std::cout << s.substr(left, right - left + 1) << std::endl;
                ++count;
                --left;
                ++right;
            }
        }

        return count;
    }
};
