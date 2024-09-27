#include <bits/stdc++.h>
// https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM
// Space optimised Tabulation
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    if(nums.size()==0) return 0;
    int n = nums.size();
    int p = nums[0];
    int pp = 0;

    for(int i=1; i<n; i++) {
        int take = nums[i] + pp;
        int notTake = p;
        pp = p;
        p = max(take, notTake);
    }
    return p;
}
