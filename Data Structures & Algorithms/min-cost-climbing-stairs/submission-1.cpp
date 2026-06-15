class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n == 2) return min(cost[0],min(cost[1],cost[0]+cost[1]));
        // vector<int>dp(n+1);
        int i = 0;
        // dp[0] = cost[0];
        // dp[1] = cost[1];
        // dp[2] = min(cost[0],cost[1],cost[0]+cost[1]);
        // dp[3] = min(dp[1],)
        int a = 0;
        int b = 0;
        int c ;
        for(int i = 2 ; i < n+1 ; i++){
           c = min(b+cost[i-1] , a+cost[i-2]);
           a = b;
           b = c;
        } 
        return c;
    }
};
