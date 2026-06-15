class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int>st;
        int n = temp.size(), i = n-1;
        st.push(n-1);
        vector<int>result(n);
        // result[n-1] = 0 ;
        while(!st.empty() and i >= 0){
            if(st.empty()) {
                st.push(i);
                result[i] = 0;
            }
            else{
                while(!st.empty() && temp[st.top()] <= temp[i]){
                    st.pop();
                }
                if(st.empty()) {
                    result[i] = 0;
                }
                else{
                    result[i] = st.top()-i;
                    // st.push(i);
                }
                 st.push(i);
            }
            i--;
        }
        return result;
    }
};
