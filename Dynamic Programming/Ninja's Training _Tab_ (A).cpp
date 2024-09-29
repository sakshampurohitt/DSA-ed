// https://www.geeksforgeeks.org/problems/geeks-training/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geeks-training
class Solution {
  public:
    // int f(int day, int last, vector<vector<int>>& dp, vector<vector<int>>& arr) {
    //     if(dp[day][last]!=-1) return dp[day][last];
    //     if(day==0) {
    //         int maxi=0;
    //         int ind=0;
    //         for(int i=0; i<3; i++) {
    //             if(i!=last) { 
    //                 if(maxi<arr[0][i]) {
    //                     maxi = arr[0][i];
    //                     ind=i;
    //                 }
    //             }
    //         }
    //         return maxi;
    //     }
    //     int maxi = 0;
    //     for(int i=0; i<3; i++) {
    //         if(i!=last) {
    //             int points = arr[day][i] + f(day-1, i, dp, arr);
    //             maxi=max(maxi, points);
    //         }
    //     }
    //     return dp[day][last] = maxi;
    // }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        vector<vector<int>> dp(n, vector<int>(4, -1));
        
        dp[0][0] = max(arr[0][1], arr[0][2]);
        dp[0][1] = max(arr[0][0], arr[0][2]);
        dp[0][2] = max(arr[0][1], arr[0][0]);
        dp[0][3] = max(arr[0][1], max(arr[0][0],arr[0][2]));
        
        for(int i=1; i<n; i++) {
            for(int next=0; next<4; next++) {
                dp[i][next] = 0;
                
                for(int task = 0; task < 3; task++) {
                    if(task!=next) {
                        int point = arr[i][task] + dp[i-1][task];
                        dp[i][next] = max(dp[i][next], point);
                    }
                }
            }
        }
        return dp[n-1][3];
        // return f(n-1, 3, dp, arr);
    }
};
