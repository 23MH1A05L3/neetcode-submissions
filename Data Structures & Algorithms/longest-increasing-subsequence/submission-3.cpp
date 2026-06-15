class Solution {
public:
    int computeLength(vector<int> &nums,int i,int prevIdx,vector<vector<int>> &dp){
        if(i >= nums.size()) return 0;
        if(dp[i][prevIdx+1] != -1){
            return dp[i][prevIdx+1];
        }
        int pickIdx = 0;
        if(prevIdx == -1 || nums[i] > nums[prevIdx]){
            pickIdx = 1+computeLength(nums,i+1,i,dp);
        }
        int nonPick = 0+computeLength(nums,i+1,prevIdx,dp);
        int maxLen = max(pickIdx,nonPick);
        return dp[i][prevIdx+1] = maxLen;
         
    }
    int lengthOfLIS(vector<int>& nums) {
        // vector<int>dp(nums.size(),-1);
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return computeLength(nums,0,-1,dp);
    }
};
