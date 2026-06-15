class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        priority_queue<vector<int>>pq;
        for(int i = 0 ; i < triplets.size() ; i++){
            if(triplets[i][0] <= target[0] && triplets[i][1] <= target[1] && triplets[i][2] <= target[2]){
                pq.push(triplets[i]);
            }
        }
        vector<int> triplet = {0,0,0};
        // vector<int> newTri = {0,0,0};
        while(!pq.empty()){
            vector<int> topTri = pq.top();
            triplet = {max(triplet[0],topTri[0]),max(triplet[1],topTri[1]),max(triplet[2],topTri[2])};
            pq.pop();
            // pq.push(newTri);
            if(triplet[0] == target[0] && triplet[1] == target[1] && triplet[2] == target[2]) return true;
        }
        return false;
    }
};
