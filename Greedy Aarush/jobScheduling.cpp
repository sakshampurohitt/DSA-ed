class Solution {
  public:
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit) {
        // code here
        int n = id.size();
        
        vector<size_t> indices(n);
        for(int i=0; i<n; i++) indices[i]=i;
        
        sort(indices.begin(), indices.end(), [&profit](int i, int j) {
            return profit[i] > profit[j];
        });
        
        int maxDeadline = *max_element(deadline.begin(), deadline.end());
        
        vector<int> timeSlot(maxDeadline+1, -1);
        
        int totalProfit=0;
        int jobsCount=0;
        
        for(int i: indices) {
            for(int j=deadline[i]; j>0; j--) {
                if(timeSlot[j]==-1) {
                    timeSlot[j]=id[i];
                    totalProfit+=profit[i];
                    jobsCount++;
                    break;
                }
            }
        }
        
        return {jobsCount, totalProfit};
    }
};
