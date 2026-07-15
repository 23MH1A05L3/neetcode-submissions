class Solution {
public:
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        vector<vector<int>>dp1(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        for(int i = 0 ; i < m ; i++){
            q.push({i,0});
        }
        for(int i = 1 ; i < n ; i++){
            q.push({0,i});
        }
        
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            int i = cur.first;
            int j = cur.second;
            if(dp[i][j] < 1){
                dp[i][j]++;
            }
            else continue;
            if(i+1 < m && dp[i+1][j] < 1 && heights[i][j] <= heights[i+1][j]){
                q.push({i+1,j});
            }
             if(i-1 >= 0 && dp[i-1][j] < 1 && heights[i][j] <= heights[i-1][j]){
                q.push({i-1,j});
            }
             if(j+1 < n && dp[i][j+1] < 1 && heights[i][j] <= heights[i][j+1]){
                q.push({i,j+1});
            }
             if(j-1 >= 0 && dp[i][j-1] < 1 && heights[i][j] <= heights[i][j-1]){
                q.push({i,j-1});
            }
        }
    
     for(int i = 0 ; i < m ; i++){
            q.push({i,n-1});
        }
        for(int i = 0 ; i < n-1 ; i++){
            q.push({m-1,i});
        }
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            int i = cur.first;
            int j = cur.second;
            if(dp1[i][j] < 1){
                dp1[i][j]++;
            }
            else continue;
            if(i+1 < m && dp1[i+1][j] < 2 && heights[i][j] <= heights[i+1][j]){
                q.push({i+1,j});
            }
             if(i-1 >= 0 && dp1[i-1][j] < 2 && heights[i][j] <= heights[i-1][j]){
                q.push({i-1,j});
            }
             if(j+1 < n && dp1[i][j+1] < 2 && heights[i][j] <= heights[i][j+1]){
                q.push({i,j+1});
            }
             if(j-1 >= 0 && dp1[i][j-1] < 2 && heights[i][j] <= heights[i][j-1]){
                q.push({i,j-1});
            }
        }
        vector<vector<int>>ans;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(dp[i][j] == 1 && dp1[i][j] == 1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
        
    }
    
};
