class MedianFinder
{
public:
    MedianFinder() = default;

    template <typename A, typename B, typename C>
    void printHeap(std::priority_queue<A, B, C> pq)
    {
        while (pq.size())
        {
            std::cout << pq.top() << " ";
            pq.pop();
        }
        std::cout << std::endl;
    }
    
    void addNum(int num)
    {
        if (maxHeap.empty() && minHeap.empty())
        {
            maxHeap.push(num);
        }
        else if (!maxHeap.empty() && minHeap.empty())
        {
            if (num > maxHeap.top())
            {
                minHeap.push(num);
            }
            else
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
            }
        }
        else if (maxHeap.empty() && !minHeap.empty())
        {
            if (num < minHeap.top())
            {
                maxHeap.push(num);
            }
            else
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            }
        }
        else
        {
            if (num < minHeap.top())
            {
                maxHeap.push(num);
            }
            else 
            {
                minHeap.push(num);
            }
        }

        int maxSize = maxHeap.size();
        int minSize = minHeap.size();
        
        if (std::abs(maxSize - minSize) > 1) // rebalance
        {
            if (maxHeap.size() > minHeap.size())
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            else
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
    }
    
    double findMedian()
    {
        int smalls = maxHeap.size();
        int larges = minHeap.size();

        printHeap(maxHeap);
        printHeap(minHeap);
        std::cout << "---" << "\n";

        if (smalls == larges)
        {
            return (minHeap.top() + maxHeap.top()) / 2.0;
        }
        else if (smalls < larges)
        {
            return minHeap.top();
        }

        return maxHeap.top();
    }

private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap;
};

/*
BBST

std::multiset

*/


/*

Optimal: two heaps

*/
