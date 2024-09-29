// https://www.geeksforgeeks.org/problems/geeks-training/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geeks-training
class Solution {
  public:
    int f(int day, int last, vector<vector<int>>& dp, vector<vector<int>>& arr) {
        if(dp[day][last]!=-1) return dp[day][last];
        if(day==0) {
            int maxi=0;
            int ind=0;
            for(int i=0; i<3; i++) {
                if(i!=last) { 
                    if(maxi<arr[0][i]) {
                        maxi = arr[0][i];
                        ind=i;
                    }
                }
            }
            return maxi;
        }
        int maxi = 0;
        for(int i=0; i<3; i++) {
            if(i!=last) {
                int points = arr[day][i] + f(day-1, i, dp, arr);
                maxi=max(maxi, points);
            }
        }
        return dp[day][last] = maxi;
    }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return f(n-1, 3, dp, arr);
    }
};
