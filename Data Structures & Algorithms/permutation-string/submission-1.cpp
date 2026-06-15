class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // string sub = s1;
        // bool nextP;
        // // if()
        // do{
        //     if(s2.contains(s1)) return true;
        //     nextP = next_permutation(s1.begin(),s1.end());
            
        // }while(nextP != false);
        // return false;
        if(s1.size() > s2.size()) return false;
        if(s1 == s2) return true;
        map<char,int>frq1;
        map<char,int>frq2;
        int i = 0,j=0;
        while(i < s1.size()){
            frq1[s1[i]]++;
            i++;
        }
        i=0;
        while(j < s2.size()){
            frq2[s2[j]]++;
            if(j-i+1 == s1.size()){
                if(frq1 == frq2) return true;
                frq2[s2[i]]--;
                if(frq2[s2[i]] == 0) frq2.erase(s2[i]);
                i++;
            }
            j++;
        }
        return false;
    }
};
