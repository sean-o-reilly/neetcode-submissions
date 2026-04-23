class Solution {
public:
    int oneBits(int n)
    {
        int count = 0;

        while (n > 0)
        {
            if (n & 0b1) ++count;
            n = n >> 1;
        }

        return count;
    }

    vector<int> countBits(int n) 
    {
        std::vector<int> res;

        for (int i = 0; i <= n; ++i)
        {
            res.push_back(oneBits(i));
        }
        return res;
    }   
};
