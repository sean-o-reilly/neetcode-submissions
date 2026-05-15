class Solution {
public:
    int characterReplacement(string s, int k)
    {
        std::array<int, 26> counts{};
        const char offset = 'A';

        int left = 0;
        int right = 0;
        counts.at(s[right] - offset)++;

        int maxWidth = -1;
        
        while (right < s.length())
        {
            int width = right - left + 1;
            int needed = width - *std::ranges::max_element(s);

            while (needed <= k)
            {
                maxWidth = std::max(maxWidth, width); // valid window
                std::cout << s.substr(left, right - left + 1) << std::endl;

                ++right; // invalid window

                if (right < s.length())
                {
                    width = right - left + 1;
                    counts.at(s[right] - offset)++;
                    needed = width - *std::ranges::max_element(counts);
                }
                else return maxWidth;
            }

            counts.at(s[left] - offset)--;
            ++left;
        }

        return maxWidth;
    }
};

/*
pseudocode:

array<int 26> counts
left = 0
right = 0

while right < s.length
    width = right - left + 1
    counts.at(right)++

    maxLetter = max_element(counts)

    // grow window
    while width - maxLetter <= k and right < s.length
        maxWidth = max(maxWidth, width)
        ++right
        counts.at(right)++
        width = right - left + 1
        maxLetter = max_element(counts)

    // shrink window
    while width - maxLetter > k
        counts.at(left)--
        ++left
        update width

    ++right

return maxWidth



using solution intuition video

keep a count of each letter in an array
slide window right while (window length - max letter) <= k
    window length - # of maxLetter tells us how many replacements are needed
    update max to window width

while replacements needed exceeds k, shrink window, keeping counts updated
*/
