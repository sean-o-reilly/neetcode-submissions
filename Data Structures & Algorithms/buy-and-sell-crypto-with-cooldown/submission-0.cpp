class Solution {
public:

    void trade(const std::vector<int>& prices, const int curr, const int buyPrice, int rollingProfit, int& maxProfit)
    {
        if (curr >= prices.size())
            return;

        if (buyPrice != -1) // we have coin, try to sell
        {
            int potentialProfit = prices.at(curr) - buyPrice;

            if (potentialProfit > 0)
            {
                int newRollingProfit = rollingProfit + potentialProfit;
                maxProfit = std::max(maxProfit, newRollingProfit);

                trade(prices, curr + 2, -1, newRollingProfit, maxProfit); // skip new index for cooldown
            }
        }
        else // we dont have coin, try to buy
        {
            trade(prices, curr + 1, prices.at(curr), rollingProfit, maxProfit); // buy by adding current price
        }

        // try doing nothing
        trade(prices, curr + 1, buyPrice, rollingProfit, maxProfit);
    }

    int maxProfit(vector<int>& prices) 
    {
        int maxProfit = 0;
        trade(prices, 0, -1, 0, maxProfit);
        return maxProfit;
    }
};

/*

How to cache memo?

store max along the way at each index?

*/



/*

Recursive decision tree

1
    Skip
        3
            Skip
            Buy
    Buy
        3 (holding 1)
            Sell (profit 2)
                4
                    Must skip, previously sold
                        0
                            Buy

                            Skip

            Cannot Buy

            Skip
                4

O(2^n)

*/