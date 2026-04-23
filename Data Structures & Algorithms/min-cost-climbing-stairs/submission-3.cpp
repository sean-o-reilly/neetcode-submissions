class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost)
    {
        int n = cost.size();

        for (int i = n - 1; i >= 0; --i)
        {
            int currCost = cost.at(i);

            // if the curr index is capable of jumping to end, cost to reach end is equal to itself
            int j1Cost = i + 1 < n ? cost.at(i + 1) : 0;
            int j2Cost = i + 2 < n ? cost.at(i + 2) : 0;

            int cheapest = std::min(j1Cost, j2Cost);

            cost.at(i) += cheapest;            
        }

        return std::min(cost[0], cost[1]);
    }
};

/*

*/