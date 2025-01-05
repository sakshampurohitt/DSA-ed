class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        if(arr.size()==0) return 0;
        if(arr.size()==1) return 1;
        sort(dep.begin(), dep.end());
        sort(arr.begin(), arr.end());
        
        int n=arr.size();
        vector<int> ans;
        ans.push_back(dep[0]);
        for(int i=1; i<n; i++) {
            bool set=false;
            for(int j=0; j<ans.size(); j++) {
                if(arr[i] > ans[j]) {
                    ans[j] = dep[i];
                    set=true;
                    break;
                }
            }
            if(!set) {
                ans.push_back(dep[i]);
            }
        }
        return ans.size();
    }
};
