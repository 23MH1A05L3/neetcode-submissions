class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>q;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == 0){
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty()){
            auto curCell = q.front();
            int i = curCell.first.first;
            int j = curCell.first.second;
            int dist = curCell.second;
            q.pop();
            if(i-1 >= 0 && grid[i-1][j] == 2147483647){
                grid[i-1][j] = min(grid[i-1][j],dist+1);
                q.push({{i-1,j},grid[i-1][j]});
            }
            if(i+1 < grid.size() && grid[i+1][j] == 2147483647){
                grid[i+1][j] = min(grid[i+1][j],dist+1);
                q.push({{i+1,j},grid[i+1][j]});
            }
            if(j-1 >= 0 && grid[i][j-1] == 2147483647){
                grid[i][j-1] = min(grid[i][j-1],dist+1);
                q.push({{i,j-1},grid[i][j-1]});
            }
            if(j+1 < grid[0].size() && grid[i][j+1] == 2147483647){
                grid[i][j+1] = min(grid[i][j+1],dist+1);
                q.push({{i,j+1},grid[i][j+1]});
            }
        }
    }
};
