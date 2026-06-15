class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size(),ans=0;
        if(n == 1) return 0;
        sort(intervals.begin(),intervals.end());
        vector<int>merge = intervals[0];
        for(int i = 1 ; i < n ; i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(merge[1] <= start){
                merge[1] = end;
                // start = min(start,merge[0]);
                
            }
            else {
                ans++;
                merge[1] = min(end,merge[1]);
            }
        }
        return ans;
    }
};
