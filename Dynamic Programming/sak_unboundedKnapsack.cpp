//code link: https://www.naukri.com/code360/problems/unbounded-knapsack_1215029 
vector<vector<int>> dp;
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) {
    dp.resize(n+1, vector<int>(w+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            if (weight[i-1] <= j) {
                dp[i][j] = max(profit[i-1] + dp[i][j - weight[i-1]], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][w];
}
