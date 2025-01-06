class Solution {

  public:
    int minC(vector<int>&coins, int sum, int i, vector<vector<int>>&memo) {
        if(sum==0) return 0;
        if(sum<0 || i ==coins.size()) return INT_MAX;
        if(memo[i][sum]!=-1) return memo[i][sum];
        
        int take=INT_MAX;
        if(coins[i]>0) {
            take=minC(coins,sum-coins[i], i, memo);
            if(take!=INT_MAX) take++;
        }
        
        int noTake = minC(coins, sum, i+1, memo);
        
        return memo[i][sum] = min(take, noTake);
    }
    int minCoins(vector<int> &coins, int sum) {
        // Your code goes here
        vector<vector<int>>memo(coins.size(), vector<int>(sum+1, -1));
        int ans = minC(coins,sum, 0, memo);
        return ans!=INT_MAX?ans:-1;
    }
};
