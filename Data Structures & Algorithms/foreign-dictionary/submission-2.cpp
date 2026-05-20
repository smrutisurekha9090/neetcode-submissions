class Solution {
   private:
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        return topo;
    }

   public:
    string foreignDictionary(vector<string>& words) {
        // adj list
        vector<int> adj[26];

        // build graph
        for (int i = 0; i < words.size() - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];
            int len = min(s1.size(), s2.size());

            // invalid case
            if (s1.size() > s2.size() && s1.substr(0, len) == s2.substr(0, len)) {
                return "";
            }

            for (int ptr = 0; ptr < len; ptr++) {
                if (s1[ptr] != s2[ptr]) {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }
        }

        vector<int> topo = topoSort(26, adj);
        string ans = "";

        vector<bool> exists(26, false);

        // only include existing chars
        for (auto& word : words) {
            for (char c : word) {
                exists[c - 'a'] = true;
            }
        }

        // count existing chars
        int countChars = 0;
        for (auto x : exists) {
            if (x) countChars++;
        }

        // cycle exists
        if (topo.size() < countChars) {
            return "";
        }
        
        for (auto node : topo) {
            if (exists[node]) {
                ans += char(node + 'a');
            }
        }
        return ans;
    }
};
