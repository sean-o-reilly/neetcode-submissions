class Solution {
public:

    // A + B overflows if MAX - A is greater than B

    // A + B > MAX
    // A > MAX - B

    void recurse(vector<int>& coins, int targetAmount, int currAmount, int currBills, std::unordered_map<int, int>& memo)
    {
        if (memo.count(currAmount))
        {
            if (currBills >= memo[currAmount]) return; // suboptimal path
            
            memo[currAmount] = std::min(memo[currAmount], currBills); // update memo with new smallest value of bills needed
        }
        else
        {
            memo[currAmount] = currBills;
        }

        // base case, combo found
        if (currAmount >= targetAmount)
        {
            return;
        }

        // else if currAmount less than, we keep searching

        // recursive branching
        for (auto coin : coins)
        {
            // catch and skip overflow
            if (coin > std::numeric_limits<int>::max() - currAmount || currAmount > std::numeric_limits<int>::max() - coin)
            {
                // 2147483647
                continue;
            }
                
            recurse(coins, targetAmount, currAmount + coin, currBills + 1, memo); // recurse for each path
        }
    }

    int coinChange(vector<int>& coins, int amount)
    {
        if (amount == 0) return 0;

        std::unordered_map<int, int> memo; // amount -> bills needed
        
        recurse(coins, amount, 0, 0, memo);

        if (memo.count(amount)) return memo[amount];

        return -1;    
    }
};

/* memo cache

[1, 2, 5], amount = 6
1, 2, 2, 1, 4 bills
1, 1, 1, 1, 1,

*/


