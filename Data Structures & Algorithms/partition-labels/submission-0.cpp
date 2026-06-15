class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map< char, pair<int,int> >intervals;
        for(int i = 0 ; i < s.size() ; i++){
            if(intervals.find(s[i]) == intervals.end()){
                intervals[s[i]].first = i;
                intervals[s[i]].second = -1;
            }
        }
        for(int i = s.size()-1 ; i >= 0 ; i--){
            if(intervals[s[i]].second == -1){
                intervals[s[i]].second = i;
            }
        }
        
        vector<pair<int,int>>pairs;
        for(auto it:intervals){
            pairs.push_back({it.second.first,it.second.second});
        }
        sort(pairs.begin(),pairs.end());
        stack<pair<int,int>>st;
        for(auto it : pairs){
            if(st.empty()){
                st.push({it.first,it.second});
                continue;
            }
            if(st.top().second > it.first){
                auto pre = st.top();
                st.pop();
                st.push({min(pre.first,it.first),max(pre.second,it.second)});
            }
            else{
                st.push({it.first,it.second});
            }
        }
        vector<int>ans(st.size());
        int i = ans.size()-1;
        while(!st.empty()){
            // cout <<   st.top().first << " " << st.top().second << endl;

            ans[i] = 1+st.top().second-st.top().first;
            st.pop();
            i--;
        }

        return ans;
    }
};
