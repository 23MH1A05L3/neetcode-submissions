class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>maximums;
        int i = 0 , j = 0,n=nums.size();
        while(j < n){
            if(dq.empty() || nums[dq.back()] >= nums[j] ){
                dq.push_back(j);
            }
            else{
                while(!dq.empty() && nums[dq.back()] < nums[j]){
                    dq.pop_back();
                }
                dq.push_back(j);
            }
            if(j-i+1 == k){
                maximums.push_back(nums[dq.front()]);
                if(dq.front() == i){
                    dq.pop_front();
                }
                i++;
            }
            j++;
        }
        return maximums;
    }
};
