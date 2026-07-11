class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLen = 0;
        int len = 0;
        unordered_set<int>s(nums.begin(),nums.end());
        for(int i = 0 ; i < nums.size() ; i++){
            if(s.find(nums[i]-1) == s.end()){
                len = 1;
                int num = nums[i];
                while(s.find(num+1) != s.end()){
                    len++;
                    num++;
                }
            }
            maxLen = max(maxLen,len);
        }
        return maxLen;
    }
    
};
