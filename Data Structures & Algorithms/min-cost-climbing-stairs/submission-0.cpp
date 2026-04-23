class Solution {
public:
    void _helper(int currIdx, int currCost, const vector<int>& cost, int& min)
    {
        if (currCost >= min) return;

        if (currIdx >= cost.size())
        {
            min = std::min(currCost, min);
            return;
        }

        currCost += cost[currIdx];


        _helper(currIdx + 1, currCost, cost, min);
        _helper(currIdx + 2, currCost, cost, min);
    }

    int minCostClimbingStairs(const vector<int>& cost)
    {
        int min = std::numeric_limits<int>::max();

        _helper(0, 0, cost, min);
        _helper(1, 0, cost, min);

        return min;
    }
};

/*

we're given a finite set of decisions, like a decision tree
at i, we can either go to i + 1 or i + 2

we can start at i = 0 or i = 1

we want minmum cost to reach top of staircase/ PAST end of array

O(n^2)? or O(2^n) -> optimize with memoization for O(n)?

maybe our memo map contains index->cheapest cost to get to that index

focusing on a decision tree, recursive shirinking the problem down rather than thinking of scale
start with trying to go two steps first maybe more optimizal on average?

[1, 2]

start at 1
    go to 2
        go to end, cost = 3
    go to end, cost = 1
start at 2
    go to end, cost = 2

[1,2,1,2]

start at 1 - $1
    go to 2 - $3
        go to 1 - $4
            go to 2 - $6
                go to end - $6
        go to 2 - $5
            go to end - $5
    go to 1 - $2
        go to 2 - $4
        go to end - $2
start at 2 -
    .....

*/