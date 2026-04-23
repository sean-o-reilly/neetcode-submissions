#include <array>

class Solution {
public:
    bool isAnagram(string s, string t)
    {
        std::array<char, 26> sCounts;
        std::array<char, 26> tCounts;

        std::fill(sCounts.begin(), sCounts.end(), 0);
        std::fill(tCounts.begin(), tCounts.end(), 0);

        const char offset = 'a';

        for (char c : s) sCounts.at(c - offset)++;
        for (char c : t) tCounts.at(c - offset)++;

        return sCounts == tCounts;
    }
};
