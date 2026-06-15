class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0 , r = n-1 , i = 0;
        // while(nums[l] == 0){
        //     l++;
        // }
        // while(nums[r] == 2){
        //     r--;
        // }
        // i = l+1;
        while(i <= r){
            if(nums[i] == 0){
                swap(nums[i],nums[l]);
                l++;
                // i++;
            }
            else if(nums[i] == 2){
                swap(nums[i],nums[r]);
                r--;
                i--;
            }
            i++;
        }
    }
};