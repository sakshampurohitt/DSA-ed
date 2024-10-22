class Solution {
  public:
    void bfs(int node, vector<vector<int>> &adj, int V, vector<int>&vis) {
        vis[node]=1;
        queue<int>q;
        q.push(node);
        
        while(!q.empty()) {
            int u=q.front();
            q.pop();
            for(int i=0; i<V; i++) {
                if(!vis[i] && adj[u][i]) {
                    q.push(i);
                    vis[i]=1;
                }
            }
        }
        
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> vis(V, 0);
        vis[0]=0;
        int countProvince=0;
        
        for(int i=0;i<V; i++) {
            if(!vis[i]) {
                bfs(i, adj, V, vis);
                countProvince++;
            }
        }
        return countProvince;
    }
};
