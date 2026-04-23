class MedianFinder
{
public:
    MedianFinder() = default;
    
    void addNum(int num)
    {
        bbst.insert(num);
    }
    
    double findMedian()
    {
        std::size_t size = bbst.size();

        if (size == 2)
        {
            double res = 0;
            for (int n : bbst) res += n;
            return res / 2.0;
        }

        auto it = bbst.begin();

        if (size == 1) return *it;

        if (size % 2 != 0)
        {
            std::advance(it, size / 2);
            return (double)*it;
        }

        std::advance(it, size / 2 - 1);

        int lhs = *it;
        std::advance(it, 1);
        int rhs = *it;

        return (lhs + rhs) / 2.0;
    }

private:
    std::multiset<int> bbst;
};

/*
BBST

std::multiset

*/
