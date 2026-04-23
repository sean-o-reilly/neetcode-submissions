class Solution {
public:

    int countSubstrings(std::string s)
    {
        int count = 0;

        for (int center = 0; center < s.size(); ++center)
        {
            int left = center;
            int right = center;

            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                ++count;
                --left;
                ++right;
            }

            // even case

            left = center;
            right = center + 1;

            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                ++count;
                --left;
                ++right;
            }
        }

        return count;
    }
};
