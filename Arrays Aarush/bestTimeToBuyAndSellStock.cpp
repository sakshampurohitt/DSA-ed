class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], profit = INT_MIN;
        for(int i=0; i<prices.size(); i++) {
            if(prices[i] < buy) buy = prices[i];
            if(prices[i]-buy > profit) {
                profit = prices[i]-buy;
            }
        }
        return profit;
    }
};
