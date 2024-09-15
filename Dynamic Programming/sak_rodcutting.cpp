class Solution{
  public:
    vector<int> dp;
    
    int util(int price[], int n) {
        if (n == 0) return 0;  
        if (dp[n] != -1) return dp[n];  
        
        int max_profit = 0;
        for (int i = 1; i <= n; i++) {
            max_profit = max(max_profit, price[i-1] + util(price, n - i));
        }
        return dp[n] = max_profit; 
    }
    
    int cutRod(int price[], int n) {
        dp.resize(n + 1, -1); 
        return util(price, n);  
    }
};
