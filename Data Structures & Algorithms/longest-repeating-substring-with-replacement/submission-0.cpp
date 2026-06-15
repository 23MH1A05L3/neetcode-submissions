class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>frq;
        int maxf = 0,left = 0 ,right = 0,res=0;
        while(right < s.size()){
            frq[s[right]]++;
            maxf = max(maxf,frq[s[right]]);
            
            while((right-left+1-maxf ) > k){
                frq[s[left]]--;
                left++;
                maxf = max(maxf,frq[s[left]]);
            }
            res = max(res,right-left+1);
            right++;
        }
        return res;
    }
};
