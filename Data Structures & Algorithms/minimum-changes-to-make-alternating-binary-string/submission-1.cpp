class Solution {
public:
    int minOperations(string s)
    {
        if (s.length() < 2) return 0;

        int count = 0;

        for (int i = 0; i < s.length(); ++i)
        {
            if (i % 2 == 0)
            {
                count += s[i] == '0';
            }
            else
            {
                count += s[i] == '1';
            }
        }

        return std::min(count, (int)s.length() - count);
    }

};

/*
0's in even indices and 1's in odd indices = answer
or
1's in even indices and 0's in odd indices = complement of answer


*/