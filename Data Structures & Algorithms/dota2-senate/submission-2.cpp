class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>r;
        queue<int>d;
        for(int i = 0 ; i < senate.size() ; i++) {
            if(senate[i] == 'R'){
                r.push(i);
            }
            else d.push(i);
        }
        int i = 0;
        set<int>st;
        while(!r.empty() && !d.empty()){
            if(st.contains(i) > 0){
                i = (i+1) %(senate.size());
                continue;
            }
           
            if(senate[i] == 'R'){
                // if((!r.empty()) && r.front() <= i)
                 if(!d.empty()) 
                 {
                    r.push(r.front());
                    r.pop();
                    st.insert(d.front());
                    d.pop();
                 }
                 else return "Radiant";
            }
            else{
                // if(!d.empty() && d.front() <= i) 
                if(!r.empty()) {
                    d.push(d.front());
                    d.pop();
                    st.insert(r.front());
                    r.pop();
                }
                else return "Dire";
            }
            
             i = (i+1) %(senate.size());
             
        }
        if(r.size() > 0) return "Radiant";
        else return "Dire";
    }
};