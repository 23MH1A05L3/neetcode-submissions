class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int palindromes = n;
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i = 0 ; i < n ; i++){
            dp[i][i] = 1;
        }
        for(int i = 0 ; i < n-1 ; i++){
            if(s[i] == s[i+1]){
                palindromes++;
                dp[i][i+1] = 1;
            }
        }
        for(int len = 3; len <= n ; len++){
            for(int i = 0 ; i <= n-len ; i++){
                int j = i+len-1;
                if(s[i] == s[j] && dp[i+1][j-1] == 1){
                    palindromes++;
                    dp[i][j] = 1;
                }
            }
        }
        return palindromes;
    }
};
