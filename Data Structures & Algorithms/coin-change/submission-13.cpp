class Solution {
public:

    int coinChange(vector<int>& coins, int amount)
    {
        // i = amount of coins, dp[i] = min coins needed to sum up to i
        std::vector<long> dp(amount + 1, std::numeric_limits<int>::max());

        dp.at(0) = 0;

        for (int i = 1; i < dp.size(); ++i)
        {
            for (int coin : coins)
            {
                int subProblemIdx = i - coin;

                if (subProblemIdx < 0) continue;

                dp.at(i) = std::min(dp.at(i), dp.at(subProblemIdx) + 1); // use long to avoid overflow here
            }
        }

        return dp.at(amount) == std::numeric_limits<int>::max() ? -1 : dp.at(amount);
    }
};


