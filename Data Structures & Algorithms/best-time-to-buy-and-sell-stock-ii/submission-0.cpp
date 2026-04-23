class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int sum = 0;

        for (int i = 0; i < prices.size() - 1; ++i)
        {
            const int profit = prices.at(i + 1) - prices.at(i);
            if (profit > 0)
            {
                sum += profit;
            }
        }

        return sum;
    }
};

/*

Maintain a sliding window size of 2
Whenever there is a profit between left and right, add the profit to sum


pseudocode:
    left = 0
    right = 1

    sum = 0

    while right < prices.size
        if prices.at(left) < prices.at(right)

        sum += prices.at(right) - prices.at(left)

*/