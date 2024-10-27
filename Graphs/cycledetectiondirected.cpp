//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool dfs(int i, vector<vector<int>> adj, int vis[], int pathvis[]) {
        vis[i] = 1;
        pathvis[i]=1;
        for(auto it: adj[i]){
            if(!vis[it]){
                if(dfs(it, adj, vis, pathvis)) return true;
            }
            else if(pathvis[it])
            return true;
        }
        pathvis[i] = 0;
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        int vis[V] = {0};
        int pathvis[V] = {0};
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathvis)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
