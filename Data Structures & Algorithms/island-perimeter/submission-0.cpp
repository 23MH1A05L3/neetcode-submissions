class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int perimeter = 0;
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(grid[i][j] == 1){
                    if(i-1 < 0 || grid[i-1][j] == 0) perimeter++;
                    if(j-1 < 0 || grid[i][j-1] == 0) perimeter++;
                    if(i+1 > row-1 || grid[i+1][j] == 0) perimeter++;
                    if(j+1 > col-1 || grid[i][j+1] == 0) perimeter++;
                }
            }
        }
        return perimeter;
    }
};