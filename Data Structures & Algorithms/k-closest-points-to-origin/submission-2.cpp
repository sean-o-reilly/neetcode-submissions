class Solution {
public:
    double getEuclideanDistance(const int x1, const int x2, const int y1, const int y2)
    {
        const int x = x1 - x2;
        const int y = y1 - y2;
        return std::sqrt((x * x) + (y * y));
    }

    struct PointPair
    {
        std::vector<int> point;
        double euclideanDistance;
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        auto cmp = [](const PointPair& A, const PointPair& B)
        {
            return A.euclideanDistance < B.euclideanDistance; // TODO < or >
        };

        std::priority_queue<PointPair, std::vector<PointPair>, decltype(cmp)> pq(cmp);

        for (const std::vector<int>& point : points)
        {
            double currDistance = getEuclideanDistance(0, point.at(0), 0, point.at(1));

            if (pq.size() < k)
            {
                pq.push({point, currDistance});
            }
            else if (currDistance < pq.top().euclideanDistance)
            {
                pq.push({point, currDistance});
                pq.pop();
            }
        }

        std::vector<std::vector<int>> res;
        while (!pq.empty())
        {
            PointPair curr = pq.top();
            pq.pop();

            res.push_back({curr.point.at(0), curr.point.at(1)});
        }

        return res;
    }
};

/*

k-most

maxHeap algo

keep a maxHeap of size k, add elements to it until it hits size k
    when it hits size k, only add elements to it if the element 
    your adding is less than the max element, then remove the 
    max element

    can store a pair or struct
    first is the euclieanDistance, second is the point value
    sort the maxHeap by euclieanDistance via lambda API


*/