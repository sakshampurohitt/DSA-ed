class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int maxi=INT_MIN;
        int n=arr.size();
        int sum=0;
        for(int i=0; i<n; i++) {
            if(sum<0) sum=0;
            sum+=arr[i];
            if(sum>maxi) maxi=sum;
        }
        return maxi;
    }
};
