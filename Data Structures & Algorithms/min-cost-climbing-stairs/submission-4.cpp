class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost)
    {
        int n = cost.size();
        for (int i = n - 1; i >= 0; --i)
            cost.at(i) += std::min(i + 1 < n ? cost.at(i + 1) : 0, i + 2 < n ? cost.at(i + 2) : 0);         
        return std::min(cost[0], cost[1]);
    }
};
