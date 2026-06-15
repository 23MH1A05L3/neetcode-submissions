class Solution {
public:
    int countMoney(vector<int>&nums,vector<int>&dp,int i ,int n){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        dp[i] = max(countMoney(nums,dp,i+1,n) , nums[i]+countMoney(nums,dp,i+2,n));
        return dp[i];
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int>dp(n,-1);
        int first = countMoney(nums,dp,0,n-1);
        vector<int>dp1(n,-1);
        int second = countMoney(nums,dp1,1,n);
        return max(first,second);
    }
};
