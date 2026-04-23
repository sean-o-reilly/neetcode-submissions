class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int gasSum = 0;
        int costSum = 0;

        for (int g : gas) gasSum += g;
        for (int c : cost) costSum += c;

        if (costSum > gasSum) return -1;

        int total = 0;
        int start = 0;

        for (int i = 0; i < gas.size(); ++i)
        {
            total += (gas[i] - cost[i]);
            if (total < 0)
            {
                start = i + 1;
                total = 0;
            }
        }
        
        return start;
    }
};


/*

for each station, test if its possible to start there
    cant cache results
O(n^2) / brute force


*/