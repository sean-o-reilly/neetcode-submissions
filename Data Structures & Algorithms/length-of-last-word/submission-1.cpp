class Solution {
public:
    int lengthOfLastWord(string s) {
        std::istringstream iss{std::move(s)};
        while (iss) iss >> s;
        return s.length();
    }
};