class NumMatrix {
public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        prefix = vector<vector<int>>(rows+1,vector<int>(cols+1,0));
        for(int i = 0 ; i < rows ; i++){
            prefix[i+1][1] = matrix[i][0]+prefix[i][1];
            
        }
        for(int i = 0 ; i < cols ; i++){
            prefix[1][i+1] = matrix[0][i]+prefix[1][i];
        }
        for(int i = 1 ; i < rows ; i++){
            for(int j = 1 ; j < cols ; j++){
                prefix[i+1][j+1] = matrix[i][j]+prefix[i+1][j]+prefix[i][j+1]-prefix[i][j];
            }
        }
        for(int i = 0 ; i <= rows ; i++){
            for(int j = 0 ; j <= cols ; j++){
                cout << prefix[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return (prefix[row2+1][col2+1] - prefix[row2+1][col1] - prefix[row1][col2+1] + prefix[row1][col1]);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */