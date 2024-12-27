class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) return;
        int i=m-1, j=n-1, high=m+n-1;

        while(j>=0) {
            if(i>=0 && nums1[i]>nums2[j]) {
                nums1[high] = nums1[i];
                i--;
            }
            else {
                nums1[high]=nums2[j];
                j--;
            }
            high--;
        }
    }
};
