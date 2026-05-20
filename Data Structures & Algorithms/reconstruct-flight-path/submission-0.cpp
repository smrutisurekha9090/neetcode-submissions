class Solution {
public:
    // EULERIAN PATH LOGIC
    unordered_map<string, multiset<string>>adj;
    vector<string>ans;

    void dfs(string node){
        while(!adj[node].empty()){
            auto it = adj[node].begin();
            string next = *it;
            adj[node].erase(it);
            dfs(next);
        }
        ans.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto &it:tickets){
            string u = it[0];
            string v = it[1];
            adj[u].insert(v);
        }
        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
