class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-1;
        int pos = -1;
        while(i>0){
            if(nums[i]>nums[i-1]){
                pos = i-1;
                break;
            }
            i--;
        }
        if(pos==-1){
            reverse(nums.begin(), nums.end());
            return;
        }
        i = n-1;
        while(i>0){
            if(nums[i]>nums[pos]){
                swap(nums[i], nums[pos]);
                reverse(nums.begin()+pos+1, nums.end());
                return;
            }
            i--;
        }
        
    }
};
