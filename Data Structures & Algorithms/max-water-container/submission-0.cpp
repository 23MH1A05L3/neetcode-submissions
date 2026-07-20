class Solution {
public:
    int maxArea(vector<int>& heights) {
        int low = 0, high = heights.size()-1;
        int maxArea = 0;
         while(low < high){
            maxArea = max(maxArea,min(heights[low],heights[high])*(high-low));
            if(heights[low] >= heights[high]){
                high--;
            }
            else low++;
         }
         return maxArea;
    }
};
