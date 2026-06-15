class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxPro = 1,minPro = 1;
        int temp ;
        int ans = nums[0];
        for(int i = 0 ; i < nums.size() ; i++){
            temp = maxPro * nums[i];
            maxPro = max(nums[i] , max(maxPro*nums[i] , minPro*nums[i]));
            minPro = min(nums[i] , min(temp , minPro*nums[i]));
            ans = max(ans,maxPro);
        }
        return ans;
    }
};
