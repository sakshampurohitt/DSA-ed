class Solution {
  public:
   vector<vector<int>> dp;

    int knapSackUtil(int W, vector<int>& wt, vector<int>& val, int n) {
        if (n == 0 || W == 0) return 0;
        if (dp[n][W] != -1) return dp[n][W];
        
        if (wt[n-1] <= W) {
            return dp[n][W] = max(val[n-1] + knapSackUtil(W - wt[n-1], wt, val, n-1),
                                  knapSackUtil(W, wt, val, n-1));
        } else {
            return dp[n][W] = knapSackUtil(W, wt, val, n-1);
        }
    }

    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n = wt.size();
        dp.resize(n + 1, vector<int>(W + 1, -1));
        return knapSackUtil(W, wt, val, n);
    }
};
