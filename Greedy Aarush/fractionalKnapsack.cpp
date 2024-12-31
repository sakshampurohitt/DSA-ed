class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // Your code here
        int n=val.size();
        multimap<double,int> mp;
        
        double max_profit = 0;
        
        for(int i=0; i<n; i++) {
            mp.insert(make_pair((double)val[i]/wt[i], i));
        }
        multimap<double,int>::reverse_iterator it;
        
        for(it = mp.rbegin(); it!=mp.rend(); it++) {
            if(capacity > 0 && capacity >= wt[it->second]) {
                max_profit+=(double)val[it->second];
                capacity-=wt[it->second];
            }
            else if(capacity > 0) {
                double fraction = (double)val[it->second]/wt[it->second];
                max_profit+=fraction*capacity;
                capacity=0;
                break;
            }
            else break;
        }
        return max_profit;
    }
};
