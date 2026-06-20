class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currMax = nums[0],currMin = nums[0];
        int totalSum = nums[0];
        int maxSum = nums[0],minSum = nums[0],total = nums[0];
        for(int i = 1 ; i < nums.size() ; i++){
            currMax = max(currMax+nums[i],nums[i]);
            currMin = min(currMin+nums[i],nums[i]);
            maxSum = max(maxSum,currMax);
            minSum = min(minSum,currMin);
            total += nums[i];
        }
        cout << total << " " << maxSum << " " << minSum << " ";
        if(total == minSum) return maxSum;
        return max(maxSum,total-minSum);
    }
};