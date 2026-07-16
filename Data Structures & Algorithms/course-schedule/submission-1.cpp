class Solution {
public:
    bool isDAG(vector<vector<int>>& adj,vector<int>& vis,vector<int>& pathVis,int source){
        vis[source] = 1;
        pathVis[source] = 1;
        for(auto v : adj[source]){
            if(pathVis[v] == 0){
                if(vis[v] == 0){
                    if(!isDAG(adj,vis,pathVis,v)) return false;
                }
            }
            else return false;
        }
        pathVis[source] = 0;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(int i = 0 ; i < prerequisites.size() ; i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
        } 
        vector<int>vis(numCourses,0);
        vector<int>pathVis(numCourses,0);
        for(int i = 0 ; i < numCourses ; i++){
            if(vis[i] == 0){
                if(!isDAG(adj,vis,pathVis,i)) {
                    cout << i << endl;
                    return false;}
            }
        }
        return true;
    }
};
