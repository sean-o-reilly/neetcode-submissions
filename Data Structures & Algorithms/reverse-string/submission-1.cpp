class Solution {
public:
    void reverseString(vector<char>& s)
    {
        const auto n = s.size();
        for (int i = 0; i < n / 2; ++i)
            std::swap(s.at(i), s.at(n - i - 1));
    }
};