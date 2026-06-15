class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);

        vector<int>dp(n);
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = dp[0]+nums[2];
        int maxRobbed = max(dp[0],max(dp[1],dp[2]));
        for(int i = 3 ; i < n ; i++){
            dp[i] = max(nums[i]+dp[i-2],nums[i]+dp[i-3]);
            maxRobbed = max(maxRobbed,dp[i]);
        }
        return maxRobbed;
    }
};
