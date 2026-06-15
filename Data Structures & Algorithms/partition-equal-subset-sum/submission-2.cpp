class Solution {
public:
    bool checkSum(vector<int>&nums,int i,int sum,vector<vector<int>>&dp){
        if(i == nums.size() || sum < 0) return false;
        if(sum == 0) return true;
        if(dp[i][sum] != -1) return dp[i][sum];
        bool pick = checkSum(nums,i+1,sum-nums[i],dp);
        bool nonPick = checkSum(nums,i+1,sum,dp);
        dp[i][sum] = (pick || nonPick);
        return dp[i][sum]; 
    }
    bool canPartition(vector<int>& nums) {
        int s = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            s += nums[i];
        }
        if(s % 2 != 0) return false;
        s = s/2;
        vector<vector<int>>dp(nums.size(),vector<int>(s+1,-1));
        return checkSum(nums,0,s,dp);
    }
};
