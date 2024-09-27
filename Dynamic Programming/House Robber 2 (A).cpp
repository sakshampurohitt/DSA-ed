// https://leetcode.com/problems/house-robber-ii/

class Solution {
public:
    int maxNonAdjascent(vector<int>& nums) {
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

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> t1, t2;
        t1.push_back(nums[0]);
        for(int i=1; i<n-1; i++) {
            t1.push_back(nums[i]);
            t2.push_back(nums[i]);
        }
        t2.push_back(nums[n-1]);

        return max(maxNonAdjascent(t1), maxNonAdjascent(t2));
    }
};
