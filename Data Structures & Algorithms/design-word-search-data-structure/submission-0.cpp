class TrieNode {
   public:
    TrieNode* child[26];
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
        isEnd = false;
    }
};

class WordDictionary {
   public:
    TrieNode* root;

    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        TrieNode* node = root;

        for (char ch : word) {
            int idx = ch - 'a';
            if (node->child[idx] == NULL) {
                node->child[idx] = new TrieNode();
            }
            node = node->child[idx];
        }
        node->isEnd = true;
    }

    bool dfs(string& word, int pos, TrieNode* node) {
        if (pos == word.size()) {
            return node->isEnd;
        }
        char ch = word[pos];

        if (ch != '.') {
            int idx = ch - 'a';
            if (node->child[idx] == NULL) {
                return false;
            }
            return dfs(word, pos + 1, node->child[idx]);
        }

        // wildcard case
        for (int i = 0; i < 26; i++) {
            if (node->child[i] != NULL) {
                if (dfs(word, pos + 1, node->child[i])) {
                    return true;
                }
            }
        }

        return false;
    }

    bool search(string word) { 
        return dfs(word, 0, root);
    }
};