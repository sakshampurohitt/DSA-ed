class Solution {
public:
    int path(int m, int n, vector<vector<int>>& dp) {
        if(dp[m][n]!=-1) return dp[m][n];
        if(m==0 || n==0) return 1;
        int left=0, right=0;
        if(m>0) left=path(m-1,n,dp);
        if(n>0) right=path(m, n-1,dp);
        return dp[m][n] = left+right;
    }
    int uniquePaths(int m, int n) {
        if(m==0 || n==0) return 1;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i=0; i<m; i++) {
            dp[i][0] = 1;
        }
        for(int j=0; j<n; j++) {
            dp[0][j] = 1;
        }
        return path(m-1, n-1, dp);
    }
};
