class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
 int m = str1.length();
        int n = str2.length();
        
      
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        int maxLength = 0;  
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    maxLength = max(maxLength, dp[i][j]); 
                } else {
                    dp[i][j] = 0;  
                }
            }
        }

        return maxLength;  
    }
};