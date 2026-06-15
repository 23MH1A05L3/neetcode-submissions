class Solution {
public:
    int findPaths(vector<vector<int>>& grid,int i,int j,int m,int n,vector<vector<int>> &dp){
        if(i >= m || j >= n || grid[i][j] == 1) return 0;
        if(i == m-1 && j == n-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int right = findPaths(grid,i,j+1,m,n,dp);
        int down = findPaths(grid,i+1,j,m,n,dp);
        dp[i][j] = (right+down);
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(),n = obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int paths = findPaths(obstacleGrid,0,0,m,n,dp);
        return paths;
    }
};