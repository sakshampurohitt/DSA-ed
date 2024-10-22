class Solution {
public:
    void bfs(vector<vector<char>>&grid, vector<vector<int>>&vis,
    queue<pair<int,int>>&q, int i, int j, int n, int m) {
        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};

        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            vis[it.first][it.second]=1;
            for(int k=0; k<4; k++) {
                int nr=it.first+dx[k];
                int nc=it.second+dy[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='1' && !vis[nr][nc]) {
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid[0].size();
        int n = grid .size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n , vector<int> (m,0));

        int ans=0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j]=='1') {
                    q.push({i,j});
                    ans++;
                    bfs(grid, vis, q, i, j, n, m);
                }
            }
        }
        return ans;
    }
};
