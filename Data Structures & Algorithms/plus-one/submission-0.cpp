class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        std::vector<int> res = digits;
        res.back() += 1;

        auto it = res.end() - 1;

        while (it != res.begin())
        {
            if (*it > 9)
            {
                *it = 0;
                --it;
                *it += 1;
            }
            else break;
        }

        if (res[0] > 9)
        {
            res[0] = 0;
            res.insert(res.begin(), 1);
        }
        
        return res;    
    }
};
