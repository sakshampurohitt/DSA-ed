class Solution {
public:
    bool bfs(int node, vector<vector<int>>&graph, vector<int>&vis, int n, int m) {
        queue<int>q;
        q.push(node);
        vis[node]=0;

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(auto it: graph[u]) {
                if(vis[it]!=-1) {
                    if(vis[it]==vis[u]) return false;
                }
                 else {
                    q.push(it);
                    if(vis[u]==0) vis[it]=1;
                    else vis[it]=0;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size(), m=graph[0].size();
        vector<int>vis(n, -1);
        for(int i=0; i<n; i++) {
            if(vis[i]==-1) {
                if(!bfs(i, graph, vis, n, m)) return false;
            }
        }
        return true;
    }
};
