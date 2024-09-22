vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfs;            
        vector<int> visited(V, 0);  
        queue<int> q;             
        
        q.push(0);
        visited[0] = 1;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
           
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = 1;
                }
            }
        }
        
        return bfs;
    }
