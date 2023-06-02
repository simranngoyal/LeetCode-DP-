class Solution {
    
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1, -1);
        dp[0] = 0;

        for(int amt = 1; amt<=amount; amt++){
            int min_coins = INT_MAX;
            for(int i=0; i<coins.size(); i++){
                int need_coins = -1;
                if(coins[i]<=amt){
                    need_coins = dp[amt-coins[i]];//coinChange(coins, amount-coins[i]);
                }
                if(need_coins !=-1 && need_coins < min_coins)min_coins = need_coins + 1;
            }
            dp[amt] = min_coins==INT_MAX ? -1 : min_coins;
        }
        return dp[amount];
    }
};

/*
-  dp is vector where each entry represents the minimum number of coins required 
   to make up the corresponding amount.
- Use a loop to iterate over the amounts from 1 to the target amount. For each
  amount, calculate the minimum number of coins needed using the coin denominations
  and the previously computed values in the table.
- inner loop checks if the current coin denomination is smaller than or equal to the
  current amount. If it is, consider using this coin denomination and update the 
  minimum number of coins needed
*/