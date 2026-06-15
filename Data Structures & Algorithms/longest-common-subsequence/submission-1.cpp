class Solution {
public:
    int computeMaxLen(string text1,string text2, int idx1,int idx2,vector<vector<int>> &dp){
        if(idx1 >= text1.size() || idx2 >= text2.size()) return 0;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(text1[idx1] == text2[idx2]) {
            dp[idx1][idx2] = 1+computeMaxLen(text1,text2,idx1+1,idx2+1,dp);
            return dp[idx1][idx2];
        }
        
        int t1 = computeMaxLen(text1,text2,idx1+1,idx2,dp);
        int t2 = computeMaxLen(text1,text2,idx1,idx2+1,dp);
        return dp[idx1][idx2] = max(t1,t2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
        int maxLen = computeMaxLen(text1,text2,0,0,dp);
        return dp[0][0];
    }
};
