class Solution {
public:
    // int maxRobbed = 0;
    // vector<int>dp = vector<int>()
    int computeMaxRobbed(vector<int>&nums,vector<int>&dp,int i){
        if(i >= nums.size()){
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        dp[i] = max(computeMaxRobbed(nums,dp,i+1),nums[i]+computeMaxRobbed(nums,dp,i+2));
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int>dp(n,-1);
        computeMaxRobbed(nums,dp,0);
        return dp[0];
    }
};
