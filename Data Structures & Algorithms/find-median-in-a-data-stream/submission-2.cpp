class MedianFinder {
public:
    MedianFinder() = default;
    
    void addNum(int num)
    {
        bbst.insert(num);
    }
    
    double findMedian()
    {
        for (int n : bbst) std::cout << n << " ";
        std:cout << std::endl;

        std::size_t size = bbst.size();

        if (size == 1) return *bbst.begin();
        if (size == 2)
        {
            double res = 0;
            for (int n : bbst) res += (double)n;
            return res / 2;
        }

        auto it = bbst.begin();

        if (size % 2 != 0)
        {
            std::advance(it, size / 2);
            return (double)*it;
        }

        std::advance(it, size / 2 - 1);

        int lhs = *it;
        std::advance(it, 1);
        int rhs = *it;

        std::cout << "Even case: " << lhs << " " << rhs << std::endl;

        return (double)(lhs + rhs) / 2;
    }

private:

    std::multiset<int> bbst;
};

/*

BBST

std::multiset




*/