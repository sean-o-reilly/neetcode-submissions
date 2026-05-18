class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        auto longest = strs.front();

        for (int i = 1; i < strs.size(); ++i)
        {
            const auto& curr = strs.at(i);
            auto iter = std::mismatch(longest.begin(), longest.end(), curr.begin()).first;
            int length = std::distance(longest.begin(), iter);
            
            if (length < longest.length())
                longest = longest.substr(0, length);
        }

        return longest;
    }
};

/*

longest = strs.first

for i = 1, i < str.size
    curr = strs at i
    mismatchA, mismatchB = mismatch(longest, curr)
    length = std distance(longest begin(), mismatchA)
    longest = longest.subtr(0, length) # trim longest string

return longest


bat vs bag
= ba

ba vs bank
= ba

ba vs band
= ba

neet vs feet
-> mismatch = begin, can return "" right away

*/