https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
class Solution {
public:
    bool detect(int i, vector<int> adj[], vector<int>& vis) {
        vis[i] = 1;
        queue<pair<int, int>> q;
        q.push({i, -1});  

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto adjnode : adj[node]) {
                if (!vis[adjnode]) {
                    vis[adjnode] = 1;
                    q.push({adjnode, node});
                } else if (adjnode != parent) {
                    return true;  
                }
            }
        }
        return false;  
    }

    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        for (int i = 0; i < V; ++i) {
            if (!vis[i]) {
                if (detect(i, adj, vis)) return true;  \
            }
        }
        return false;  }
};
