class Solution {
   public:
    int bfs(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({x, y});

        vis[x][y] = 1;
        int area = 1;

        // only 4 directions
        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];

                if( nRow >= 0 && nRow < n && nCol >= 0 && nCol < m 
                    && grid[nRow][nCol] == 1 && !vis[nRow][nCol]) 
                {
                    vis[nRow][nCol] = 1;
                    area++;

                    q.push({nRow, nCol});
                }
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    int area = bfs(grid, i, j, vis);
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};
