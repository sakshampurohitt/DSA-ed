class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int min_price = INT_MAX;
        int max_profit = 0;
        for (int price : prices) {
            if (price < min_price) {
                min_price = price; 
            } else if (price - min_price > max_profit) {
                max_profit = price - min_price;  
            }
        }

        return max_profit;
    }
};
