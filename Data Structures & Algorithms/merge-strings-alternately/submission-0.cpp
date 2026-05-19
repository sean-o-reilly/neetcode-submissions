class Solution {
public:
    string mergeAlternately(string word1, string word2)
    {
        int left = 0;
        int right = 0;
        std::string res;

        while (left < word1.length() || right < word2.length())    
        {
            if (left < word1.length())
            {
                res += word1.at(left);
                ++left;
            }

            if (right < word2.length())
            {
                res += word2.at(right);
                ++right;
            }
        }

        return res;
    }
};