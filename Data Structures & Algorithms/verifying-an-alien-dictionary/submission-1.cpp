class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int>posOfAlpha;
        for(int i = 0 ; i < order.size(); i++){
            posOfAlpha[order[i]] = i;
        }
        for(int i = 0 ; i < words.size()-1 ; i++){
            string a = words[i], b = words[i+1];
            int aLen = a.size(),bLen = b.size();
            int idx = 0;
            while(idx < aLen && idx < bLen && a[idx] == b[idx]) idx++;
            if(idx < aLen && idx == bLen) return false;
            if(idx < aLen && idx < bLen && a[idx] != b[idx]){
                if(posOfAlpha[a[idx]] > posOfAlpha[b[idx]]) return false;
            }
        }
        return true;
    }
};