class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        vector<set<char>> rows(n), cols(n), boxs(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') continue;

                char c = board[i][j];
                int boxIdx = 3 * (i / 3) + (j / 3);

                if (rows[i].count(c) || cols[j].count(c) || boxs[boxIdx].count(c)) {
                    return false;
                }

                rows[i].insert(c);
                cols[j].insert(c);
                boxs[boxIdx].insert(c);
            }
        }
        return true;
    }
};
