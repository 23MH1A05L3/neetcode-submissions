class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(accumulate(gas.begin(),gas.end(),0) < accumulate(cost.begin(),cost.end(),0)) return -1;
        int n = gas.size();
        vector<int>rem(n,0);

        int idx = 0,total=0;
        for(int i = 0 ; i < n ; i++){
            total += (gas[i]-cost[i]);
            if(total < 0){
                total = 0;
                idx = i+1;
            }
        }
        return idx;
    }
};
