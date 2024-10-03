// https://leetcode.com/problems/minimum-falling-path-sum/
class Solution {
public:
    // Memoization
    int calcMin(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        if(j<0 || j>=mat[0].size()) return 1e8;
        if(i==0) return mat[0][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int up = calcMin(i-1, j, mat, dp) + mat[i][j]; 
        int ld = calcMin(i-1, j-1, mat, dp) + mat[i][j];
        int rd = calcMin(i-1, j+1, mat, dp) + mat[i][j];

        return dp[i][j] = min(up, min(ld, rd));
    }
    //Space optimised Tabulation
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        //vector<vector<int>> dp(n, vector<int>(m, 0));
        vector<int> dp(m,0),cur(m,0);
        for(int j=0; j<m; j++) {
            dp[j] = mat[0][j];
            //  dp[0][j] = mat[0][j];
        }

        for(int i=1; i<n; i++) {
            for(int j=0; j<m; j++) {
                int u, ld=1e8, rd=1e8;
                u=dp[j];
                if(j>0) ld=dp[j-1];
                if(j<m-1) rd=dp[j+1];
                cur[j] = min(u, min(ld, rd)) + mat[i][j];
            }
            dp=cur;
        }


        int maxi = 1e8;
        for(int i=0; i<m; i++) {
            maxi = min(maxi, dp[i]);
        }
        return maxi;
    }
};
