class TrieNode {
   public:
    TrieNode* child[26];
    string word;

    TrieNode() {
        for (int i = 0; i < 26; i++) child[i] = NULL;
        word = "";
    }
};

class Solution {
   public:
    vector<string> ans;

    void insert(TrieNode* root, string word) {
        TrieNode* node = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (node->child[idx] == NULL) node->child[idx] = new TrieNode();

            node = node->child[idx];
        }
        node->word = word;
    }

    void dfs(int r, int c, vector<vector<char>>& board, TrieNode* node) {
        char ch = board[r][c];

        if (ch == '#') return;

        node = node->child[ch - 'a'];

        if (node == NULL) return;

        if (node->word != "") {
            ans.push_back(node->word);

            node->word = "";
        }
        board[r][c] = '#';

        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (auto& d : dir) {
            int nr = r + d[0];
            int nc = c + d[1];

            if (nr >= 0 && nc >= 0 && nr < board.size() && nc < board[0].size()) {
                dfs(nr, nc, board, node);
            }
        }
        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

        for (string& word : words) insert(root, word);

        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dfs(i, j, board, root);
            }
        }
        return ans;
    }
};