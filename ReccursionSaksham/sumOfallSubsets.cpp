class Solution {
private: 
void helper(int ind, vector<int>& arr, int n, vector<int>& ans, int sum){
    if(ind == n){
        ans.push_back(sum);
        return;
    }
    helper(ind+1, arr, n, ans, sum);
    helper(ind+1, arr, n, ans, sum+arr[ind]);
}
  public:
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> ans(n);
        helper(0, arr, n, ans, 0);
        return ans;
        
    }
};
