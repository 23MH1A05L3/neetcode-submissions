class Solution {
public:
    // int minCoins = INT_MAX;
    int countMinCoins(vector<int>& coins,int amount,vector<int>& dp){
        if(amount == 0){
            // minCoins = min(minCoins,coinCount);
            return 0;
        }
        // if(amount < 0 ) return 0;
        if(dp[amount] != -1) return dp[amount];
        int coinCount = 1e9;
        for(int i = 0 ; i < coins.size() ; i++){
            if(coins[i] <= amount) {
                coinCount = min(coinCount,1 + countMinCoins(coins,amount-coins[i],dp));
                // dp[amount] = coinCount;
            }
            
        }
        dp[amount] = coinCount;
        return coinCount;
        

    }
    int coinChange(vector<int>& coins, int amount) {
        // int coinCount = 0;
        vector<int>dp(amount+1,-1);
        int mini = countMinCoins(coins,amount,dp);
        if(mini >= 1e9) return -1;
        return mini;
    }
};
