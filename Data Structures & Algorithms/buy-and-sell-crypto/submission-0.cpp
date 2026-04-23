class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int buy = 0;
        int sell = 1;
        int max = 0;

        while (sell < prices.size())
        {
            if (prices[sell] < prices[buy]) // bad, adjust window
            {
                buy = sell;
            }
            
            if (prices[buy] < prices[sell]) // good, lets try buying
            {
                const int currProfit = prices[sell] - prices[buy];
                max = std::max(currProfit, max);
            }
            ++sell;
        }

        return max;
    }
};


// -- brute force -- 

// for each price, check highest price pair of buy and sell
// O(n^2) time, O(1) space

//  -- sliding window for better time --

// cannot sort because order matters.

// [10, 1, 5, 6, 7, 1]

// [5, 7, 3, 1, 4, 10]

// [1, 3]

// [4, 4, 4, 7, 2, 7]

// [10, 8, 4, 2, 1]
// [2, 1]

// some way to find the min

// buy index and sell index
// buy index starts at first, sell starts at second

// move the sell index forward, if the sell index price becomes less than buy index price, move the buy index to sell index
// track max profit 

// buy = 0
// sell = 1
// max = 0

// while (sell < size of prices)
//      if sell price less than buy price
//          move buy to sell, then move sell forward one
//      else if buy price less than sell price
//          record current profit, update max
//      else if equal, move sell forward



// return max