class Solution {
public:
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& vis, queue<pair<int, int>>& q, int m, int n) {
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            vis[curr.first][curr.second] = 1;

            for (int i = 0; i < 4; i++) {
                int x = curr.first + dx[i];
                int y = curr.second + dy[i];
                
                if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == '1' && vis[x][y] == 0) {
                    vis[x][y] = 1;
                    q.push({x, y});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && vis[i][j] == 0) {
                    count++;
                    q.push({i, j});
                    bfs(grid, vis, q, m, n);
                }
            }
        }
        
        return count;
    } 
};
