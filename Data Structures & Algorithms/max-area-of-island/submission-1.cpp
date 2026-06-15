class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int row = grid.size();
        int col = grid[0].size();
        int maxArea = 0;
        int area = 0;
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(grid[i][j] == 1){
                    area = 0;
                    grid[i][j] = 0;
                    q.push({i,j});
                    while(!q.empty()){
                        auto u = q.front();
                        q.pop();
                        area++;
                        int x = u.first;
                        int y = u.second;
                        if(x-1 >= 0 && grid[x-1][y] == 1){
                            q.push({x-1,y});
                            grid[x-1][y] = 0;
                        }
                        if(x+1 < row && grid[x+1][y] == 1){
                            q.push({x+1,y});
                            grid[x+1][y] = 0;
                        }
                        if(y-1 >= 0 && grid[x][y-1] == 1){
                            q.push({x,y-1});
                            grid[x][y-1] = 0;
                        }
                        if(y+1 < col && grid[x][y+1] == 1){
                            q.push({x,y+1});
                            grid[x][y+1] = 0;
                        }
                    }
                    maxArea = max(maxArea,area);
                }
            }
        }
        return maxArea;
    }
};
