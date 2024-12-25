class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1;
        int n = nums.size();
        if(n==1) return;
        if(n==2) {
            swap(nums[0], nums[1]);
            return;
        }
        for(int i=n-2; i>=0; i--) {
            if(nums[i]<nums[i+1]) {
                ind=i;
                break;
            }
        }
        if(ind!=-1) {
            for(int i=n-1; i>ind; i--) {
                if(nums[i]>nums[ind]) {
                    swap(nums[ind], nums[i]);
                    break;
                }
            }
        }
        reverse(nums.begin()+ind+1, nums.end());
        return;
    }
};
