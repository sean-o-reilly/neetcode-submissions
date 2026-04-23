class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int left = 0;
        int right = 0;
        int max = 0;
        std::unordered_set<char> visited;

        while (right < s.length())  
        {
            char rightChar = s[right];
            while (visited.count(rightChar))
            {
                char leftChar = s[left];
                visited.erase(leftChar);
                ++left;
            }

            visited.insert(rightChar);
            max = std::max(max, right - left + 1);
            ++right;
        }  

        return max;
    }
};

// brute force:
//  for each char in string
//      see what the longest string you can get is, before any repeating characters
//      store each "seen" character in a set, one you come across a character that is
//      already in the seen set, record that as potential max length, move onto next character in string
// O(n^2) time and space

// potential better solution
// try sliding window approach, since we're looking for a subset.
// can probably shrink or expand the window size more efficiently

// "xyzxyzabcxyzxyz"

// on repeating character found, move left boundary->
//      or *while reapting character found, move left boundary?
// continously move right boundary->
// break when right hits end
// pop chars until we  pop the duplicate char? no search needed?

// keep set of characters in substring
// Finding out if substring contains repeat is O(n)

// O(n) time, O(m) space where m = max substring width
// left = first
// right = first
// max = 0
//
// set of unique chars
// while (right < s length)
//  if unique contains right char
//      while unique contains right char
//          unique remove left char
//          ++left
//  else
//     unique insert right char
//     ++right

//  max window = right - left + 1
//  


// "abcdeabcabc"