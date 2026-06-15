class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        int leftMax = heights[0],rightMax = heights[n-1];
        int l = 0,r=n-1,water=0;
        while(l < r){
            if(leftMax < rightMax){
                l++;
                leftMax = max(leftMax,heights[l]);
                water += (leftMax-heights[l]);
            }
            else{
                r--;
                rightMax = max(rightMax,heights[r]);
                water += (rightMax-heights[r]);
            }
        }
        return water;
    }
};
