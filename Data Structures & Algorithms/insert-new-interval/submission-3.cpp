class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        stack<vector<int>>inter ;
        vector<vector<int>>resInter;
        int i = 0 , n= intervals.size();
        for(int i  = n-1 ; i >= 0; i--){
            inter.push(intervals[i]);
        }
        int flag = 0;
        i = 0;
        while(!inter.empty()){
            auto topInt = inter.top();
            int a = topInt[0];
            int b = topInt[1];
            int c = newInterval[0];
            int d = newInterval[1];
            if((a <= c && c <= b) || (a <= d && d <= b) || (c <= a && b <= d)){
                inter.pop();
                newInterval= {min(a,c) ,max(b,d)} ;
            }
            else if(b < c) {
                inter.pop();
                resInter.push_back(topInt);
            }
            else if(a > d || (i+1) == n){
                resInter.push_back(newInterval);
                flag = 1;
                while(!inter.empty()){
                    resInter.push_back(inter.top());
                    inter.pop();
                }
            }
            i++;
        }
        if(inter.empty() && resInter.size() == 0){
            flag = 1;
            resInter.push_back(newInterval);
            }
        if(flag == 0) resInter.push_back(newInterval);
        return resInter;
    }
};
