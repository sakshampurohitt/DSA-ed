class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n) {
            int pos=nums[i]-1;
            if(nums[pos]==nums[i]) {
                if(pos==i) i++;
                else return nums[i];
            }
            else swap(nums[pos], nums[i]);
        }
        return -1;
    }
};
