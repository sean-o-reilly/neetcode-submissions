class Solution {
public:
    bool criteriaMet(std::unordered_map<char, int> essential, std::unordered_map<char, int> counts)
    {
        for (auto [key, val] : essential)
            {
                if (counts[key] < essential[key]) // if count is less than whats needed
                {
                    return false;
                }
            }
        std::cout << "Criteria met" << std::endl;
        return true;
    }
    // criteria is met if each essential char has a count of 1 or more
    // O(m)

    void printMap(std::unordered_map<char, int> m)
    {
        for (auto [key, val] : m)
        {
            std::cout << key << " : " << val << std::endl;
        }
    }

    string minWindow(string s, string t)
    {
        if (t.length() > s.length())
        {
            return "";
        }

        if (t == s) return t;

        std::unordered_map<char, int> essential;
        for (char c : t) essential[c]++;

        std::unordered_map<char, int> counts;

        int left = 0;
        int right = 0;

        std::string min = "";

        while (left < s.length())
        {
            while (!essential.count(s[left])) // move left bound until essential char is found
            {
                if (counts[s[left]] > 0)
                {
                    counts[s[left]]--;
                }

                ++left;
                if (left >= s.length()) break;

                right = std::max(left, right);
            }

            // move right bound until criteria is met
            while (!criteriaMet(essential, counts) && right < s.length())
            {
                counts[s[right]]++;
                ++right;
            }

            std::string curr = s.substr(left, right - left);
            std::cout << "Window: " << curr << std::endl;
            printMap(counts);

            // store off minimum
            if (criteriaMet(essential, counts) && left < right && min.length() > curr.length())
            {
                min = curr;
                std::cout << "New min: " << min << std::endl;
            }

            if (min == "" && criteriaMet(essential, counts))
            {
                min = curr;
                std::cout << "First min: " << min << std::endl;
            }

            if (counts.count(s[left]))
            {
                counts[s[left]]--;
            }
            ++left;
        }

        return min;
    }
};

// HANDLE EDGE CASES

/*
BJKASDCJLASUIPECKSABZFXCO

using deque or list as a window (maybe just two indices)
    window:
        move left bound until essential char is found
        move right bound until criteria is met
        store off minimum
        repeat

BJKASDCJLASUIPECKSABZFXCO

sliding window -> perform t.size operations for each char in string

would not have to recalc counts for each substring, when we push or pop to deque
we can update the hashmap of counts in O(1)

resize and count in O(1)
O(t.size()) to check for criteria
O(n) to slide window

ABCXXXXXXXXXXXXXX

window:
    window = ""
    left = 0 # first char is essential
    # move right until criteria is met
    window = "BJKASDC"
    min = "BJKASDC"

    --- 

    window = "BJKASDC"
    # move left bound until essential
    window = "ASDC"
    # move right until critera met
    window = "ASDCJLASUIPECKSAB"
    min stays same

    ---

    window = "ASDCJLASUIPECKSAB"
    # move left
    "CJLASUIPECKSAB"
    # move right until criteria, but its already met
    "CJLASUIPECKSAB"
    min stays

    ---

    window = "CJLASUIPECKSAB"
    # move left
    "ASUIPECKSAB"
    # move right until criteria (already met)
    "ASUIPECKSAB"
    min stays

    ---

    window = "ASUIPECKSAB"
    # move left
    "CKSAB"
    # while criteria not met, ++right (already is, nothing changes)
    "CKSAB" 
    min = CKSAB

    ---

    window = "CKSAB"
    move left
    "AB"
    # while criteria not met, ++right
    "ABZFXCO"
    min stays

    ---
    window = "ABZFXCO"
    # move left
    "BZFXCO"

    while criteria not met and right < size - 1, ++right
    "BZFXCO"
    min stays
    
    ---
    "BZFXCO"
    # move left
    "CO"
    while criteria not met and right < size - 1, ++right
    # min stays

    window = "CO"
    move left until it hits the end

    end.
    min = "CKSAB"

data structure ideas:
    hashmap from character->count in the substring
    queue or deque to store a "window"

Check criteria -> O(m) where m is size of t
Traverse hashmap and ensure all criteria values have count of at least 1

move left to essential
move right until criteria is hit and right isn't out of bounds
stop when left hits end

OUZODYXAZV

# move left to Z (index 2)
# start right at Z, move until criteria is met
window = "ZODYX"

# move left to essential
window = "YX"
# move right until criteria and !out of bounds
window = "YXAZ"

# move left to ess
window = "XAZ"
# move right until criteria  or out of bounds
window = "XAZV"

# move left to ess
"ZV"
# cant move right
# move left to end, done

*/


/*
Brute force O(n^2):
    check every sub string starting with size of t, then t + 1, t + 2
    essential increase window size until first occurence of a substring with all characters
*/