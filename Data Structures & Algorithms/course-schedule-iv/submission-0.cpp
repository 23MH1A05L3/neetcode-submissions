class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>>dist(numCourses,vector<int>(numCourses,INT_MAX));
        int edges = prerequisites.size();
        for(int i = 0 ; i < edges ; i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            dist[u][v] = 1;
        }
        for(int k = 0 ; k < numCourses ; k++){
            for(int i = 0 ; i < numCourses ; i++){
                for(int j = 0 ; j < numCourses; j++){
                    if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][j] > dist[i][k]+dist[k][j]){
                        dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
            }
        }
        vector<bool>isIndirect(queries.size(),false);
        for(int i = 0 ; i < queries.size() ; i++){
            int u = queries[i][0];
            int v = queries[i][1];
            if(dist[u][v] != INT_MAX) isIndirect[i] = true;
        }
        return isIndirect;
    }
};