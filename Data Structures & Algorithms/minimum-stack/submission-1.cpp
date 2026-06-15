#include<bits/stdc++.h>
using namespace std;
class MinStack {
public:
    stack<int> st;
    // int mini = INT_MAX;
    stack<int> miniSt;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(miniSt.empty()) miniSt.push(val);
        else {
            // while(!miniSt.empty() && st.top() > val){
            //     miniSt.pop();
            // }
            if(miniSt.top() > val ) miniSt.push(val);
            else miniSt.push(miniSt.top());
        }
    }
    
    void pop() {
        st.pop();
        miniSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return miniSt.top();
    }
};
