class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);

        vector<int>dp(n);
        int a = nums[0];
        int b = nums[1];
        int c = a+nums[2];
        int maxRobbed = max(b,c);
        for(int i = 3 ; i < n ; i++){
            int d = max(nums[i]+b,nums[i]+a);
            // maxRobbed = max(maxRobbed,d);
            a = b;
            b = c;
            c = d;
        }
        return max(b,c);
    }
};
