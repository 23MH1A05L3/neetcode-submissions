class Solution {
    
public:
    
    vector<int>cs = vector<int>(100000,-1);
    int climbStairs(int n) {
        if(n <= 2) {
            cs[n] = n;
            return n;
        }
        
        if(cs[n] != -1) return cs[n];
        return cs[n] = climbStairs(n-1)+climbStairs(n-2);
        
    }
};
