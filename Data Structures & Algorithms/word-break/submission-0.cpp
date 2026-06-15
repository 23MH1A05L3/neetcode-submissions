class Solution {
public:
    static bool comp(string a, string b){
        return a.size() < b.size();
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        sort(wordDict.begin(),wordDict.end(),comp);
        vector<int>dp(n+1,0);
        dp[n]=1;
        for(int start = n-1; start >= 0 ; start--){
            for(auto word : wordDict){
                if(start + word.size() > n){
                    break;
                }
                else if(word == s.substr(start,word.size())){
                    dp[start] = dp[start+word.size()];
                }
                if(dp[start] == 1) break;
            }
        }
        if(dp[0] == 1) return true;
        return false;
    }
};
