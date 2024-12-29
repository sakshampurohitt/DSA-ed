class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0;
        int sum=0;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==1) {
                sum++;
                maxi = max(sum, maxi);
            }
            else sum=0;
        }
        return maxi;    
    }
};
