class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>,int>> q;
        int n = grid.size();
        int m = grid[0].size();

        int fresh = 0;
        int rotten = 0;

        int time = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        int delRow[] = {-1, 1, 0, 0};
        int delCol[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;

            q.pop();

            time = max(time, t);

            for (int i = 0; i < 4; i++) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 1) {
                    grid[nRow][nCol] = 2;

                    rotten++;
                    q.push({{nRow, nCol}, t + 1});
                }
            }
        }
        if (fresh != rotten) return -1;
        return time;
    }
};
