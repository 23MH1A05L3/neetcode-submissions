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
        vector<int>frq1(26);
        vector<int>frq2(26);
        int i = 0,j=0;
        while(i < s1.size()){
            frq1[s1[i]-'a']++;
            i++;
        }
        i=0;
        while(j < s2.size()){
            frq2[s2[j]-'a']++;
            if(j-i+1 == s1.size()){
                if(frq1 == frq2) return true;
                frq2[s2[i]-'a']--;
                // if(frq2[s2[i]] == 0) frq2.erase(s2[i]);
                i++;
            }
            j++;
        }
        return false;
    }
};
