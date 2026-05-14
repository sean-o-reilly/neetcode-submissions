#include <ranges>

class Solution {
public:
    int minOperations(string s)
    {
        int count{};
        for (auto [i, c] : std::views::zip(std::views::iota(0), s)) {
            if (i % 2 == 0) count += s[i] == '0';
            else count += s[i] == '1';
        }
        return std::min(count, (int)s.length() - count);
    }

};

/*
0's in even indices and 1's in odd indices = answer
or
1's in even indices and 0's in odd indices = complement of answer


*/