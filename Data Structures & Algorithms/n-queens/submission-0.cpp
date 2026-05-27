class Solution {
   public:
    bool isSafe(vector<string>& board, int x, int y, int n) {
        // check for column if queen present or not
        for (int row = 0; row < x; row++) {
            if (board[row][y] == 'Q') {
                return false;
            }
        }
        // left upper diagonal
        int row = x;
        int col = y;
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') {
                return false;
            }
            row--;
            col--;
        }
        // right upper diagonal
        row = x;
        col = y;

        while (row >= 0 && col < n) {
            if (board[row][col] == 'Q') {
                return false;
            }
            row--;
            col++;
        }
        return true;
    }
    void solve(int row, vector<string>& board, vector<vector<string>>& ans, int n) {
        if (row >= n) {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                solve(row + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        string s(n, '.');

        for (int i = 0; i < n; i++) {
            board[i] = s;
        }

        vector<vector<string>> ans;
        solve(0, board, ans, n);
        return ans;
    }
};