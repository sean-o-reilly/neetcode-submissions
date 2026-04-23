class Solution {
public:
    int scoreOfString(string s)
    {
        int sum = 0;

        for (int i = 1; i < s.length(); ++i)
        {
            sum += std::abs(s[i] - s[i - 1]);
        }

        return sum;
    }
};

/*

c: 99
o: 111
d: 100
e: 101


*/