class Solution {
public:
    int search(vector<int>& nums, int target) {
        // return 0;
        int n = nums.size();
        int low = 0 ,high = n-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] >= nums[low]){
                if(target < nums[low] || target > nums[mid]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
            else{
                if(target < nums[mid] || target > nums[high]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
        }
        return -1;
    }
};
