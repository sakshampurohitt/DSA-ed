// https://leetcode.com/problems/triangle/
class Solution {
public:
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int m=grid.size();
        int n=grid[0].size();
        if(i==m-1) return grid[m-1][j];
        int down = f(i+1, j, grid, dp);
        int diag = f(i+1, j+1, grid, dp);
        return dp[i][j] = min(down, diag) + grid[i][j];
    }
    int minimumTotal(vector<vector<int>>& tr) {
        int n = tr.size();
        vector<vector<int>>dp(n,vector<int>(n));
        for(int j=0; j<n; j++) dp[n-1][j] = tr[n-1][j];
        for(int i=n-2; i>=0; i--) {
            for(int j=i; j>=0; j--) {
                int d = dp[i+1][j];
                int dg = dp[i+1][j+1];
                dp[i][j] = min(d,dg) + tr[i][j];
            }
        }
        return dp[0][0];
    }
};
