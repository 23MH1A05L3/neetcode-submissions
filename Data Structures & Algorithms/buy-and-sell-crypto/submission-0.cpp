class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>highest(n);
        highest[n-1] = prices[n-1];
        for(int i = n-2 ; i >= 0 ; i--){
            highest[i] = max(highest[i+1],prices[i+1]);
        }
        int maxProfit = 0;
        for(int i = 0 ; i < n ; i++){
            maxProfit = max(maxProfit,highest[i]-prices[i]);
        }
        return maxProfit;
    }
};
