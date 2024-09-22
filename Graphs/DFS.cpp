class Solution {
  public:
    void dfs(int node, vector<int> adj[], vector<int> &visited, vector<int> &result) {
        visited[node] = 1;
        result.push_back(node);

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, result);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        vector<int> result;
        dfs(0, adj, visited, result);
        return result;
    }
};
