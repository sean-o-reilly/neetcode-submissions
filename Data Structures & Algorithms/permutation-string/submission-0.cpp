class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        const char offset = 'a';
        std::array<int, 26> target{};
        for (auto c : s1)
            target.at(c - offset)++;

        std::array<int, 26> counts{};

        int left = 0;
        int right = 0;

        while (right < s1.size() - 1)
        {
            counts.at(s2[right] - offset)++;
            ++right;
        }
        
        while (right < s2.length())
        {
            counts.at(s2[right] - offset)++;

            if (counts == target)
            {
                for (auto n : counts) std::cout << n << " ";
                std::cout << std::endl;
                for (auto n : target) std::cout << n << " ";
                std::cout << std::endl;
                return true;
            }

            counts.at(s2[left] - offset)--;
            if (counts.at(s2[left] - offset) < 0)
            {
                for (auto n : counts) std::cout << n << " ";
                throw std::logic_error("left < 0");
            }
            ++left;
            ++right;
        }

        return false;
    }
};

/*
lecaabee

array<int, 26> target
fill target with alphabetically counts
"abc" -> [1, 1, 1, 0, 0, ...]
counts = new array

left = 0
right = 0

while right - left < s1.size - 1 # grow window to right
    counts.at(right)++
    ++right 

while right < s2.size # move window right
    counts.at(right)++

    if counts == target, return true
    
    counts.at(left)-- # shrink window left->right
    ++left

    ++right

return false

window size = len(s1)
check if at any position, the sliding window contains all three letters

order-agnostic count

le(cab)ee
abc
true

lecaabee
abc
false

axbxaxb
ab
false

bbbacbbb
abc
true

abababxxxccccbbbxxxcca
abc
false

aabbcc
abc
false

*/
