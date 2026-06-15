class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        map<pair<int,int>,int>mo;
        queue<pair<int,int>>q;
        for(int j = 0 ; j < n ; j++){
            if(board[0][j] == 'O'){
                q.push({0,j});
                mo[{0,j}]++;
            }
            if(board[m-1][j] == 'O'){
                q.push({m-1,j});
                mo[{m-1,j}]++;
            }
        }
        for(int i = 1 ; i < m-1 ; i++){
            if(board[i][0] == 'O'){
                q.push({i,0});
                mo[{i,0}]++;
            }
            if(board[i][n-1] == 'O'){
                q.push({i,n-1});
                mo[{i,n-1}]++;
            }
        }
        while(!q.empty()){
            auto curCell = q.front();
            q.pop();
            int i = curCell.first;
            int j = curCell.second;
            if(i+1 < m && board[i+1][j] == 'O' && mo.find({i+1,j}) == mo.end() ){
                q.push({i+1,j});
                mo[{i+1,j}]++;
            }
            if(i-1 >= 0 && board[i-1][j] == 'O' && mo.find({i-1,j}) == mo.end()){
                q.push({i-1,j});
                mo[{i-1,j}]++;
            }
            if(j-1 >= 0 && board[i][j-1] == 'O' && mo.find({i,j-1}) == mo.end()){
                q.push({i,j-1});
                mo[{i,j-1}]++;
            }
            if(j+1 < n && board[i][j+1] == 'O' && mo.find({i,j+1}) == mo.end()){
                q.push({i,j+1});
                mo[{i,j+1}]++;
            }
        }
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] == 'O' && mo.find({i,j}) == mo.end()){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
