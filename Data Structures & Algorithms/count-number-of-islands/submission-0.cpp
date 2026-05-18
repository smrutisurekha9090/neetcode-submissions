class Solution {
   public:
    void dfs(vector<vector<char>>& grid, int x, int y) {
        int n = grid.size();
        int m = grid[0].size();
        if (x < 0 || x == n || y < 0 || y == m || grid[x][y] == '0') return;
        grid[x][y] = '0';
        dfs(grid, x + 1, y);
        dfs(grid, x - 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x, y - 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int isIsland = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    isIsland++;
                    dfs(grid, i, j);
                }
            }
        }
        return isIsland;
    }
};
