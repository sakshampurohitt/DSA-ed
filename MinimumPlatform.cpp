class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int platforms = 0, maxPlatforms = 0;
        int i = 0, j = 0; 

        while (i < arr.size()) {
            if (arr[i] <= dep[j]) {
              
                platforms++;
                maxPlatforms = max(maxPlatforms, platforms);
                i++;
            } else {
                platforms--;
                j++;
            }
        }
        return maxPlatforms;
    }

};
