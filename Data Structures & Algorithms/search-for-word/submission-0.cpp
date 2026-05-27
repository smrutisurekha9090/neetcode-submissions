class Solution {
   public:
    bool solve(int idx, int i, int j, int n, int m, vector<vector<char>>& board, string& word) {
        if (idx == word.size()) return true;
        if (i < 0 || j < 0 || i == n || j == m || board[i][j] != word[idx]) return false;
        char ch = board[i][j];
        board[i][j] = '#';

        bool op1 = solve(idx + 1, i + 1, j, n, m, board, word);
        bool op2 = solve(idx + 1, i, j + 1, n, m, board, word);
        bool op3 = solve(idx + 1, i - 1, j, n, m, board, word);
        bool op4 = solve(idx + 1, i, j - 1, n, m, board, word);

        board[i][j] = ch;

        return op1 || op2 || op3 || op4;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (solve(0, i, j, n, m, board, word)) return true;
                }
            }
        }
        return false;
    }
};