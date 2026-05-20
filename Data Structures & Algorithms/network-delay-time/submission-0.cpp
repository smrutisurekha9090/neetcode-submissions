class Solution {
public:
    // DIJKSTRA'S ALGO
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // adjacency list
        vector<pair<int,int>> adj[n+1];
        for(auto &it:times){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
        }

        priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});

        vector<int>dist(n+1,INT_MAX);
        dist[k] = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int d = it.first;
            int node = it.second;

            for(auto iter : adj[node]){
                int adjNode = iter.first; 
                int edW = iter.second;
                if(d + edW < dist[adjNode]){
                    dist[adjNode] = d + edW ;
                    pq.push({ dist[adjNode] ,adjNode});
                }
            }
        }
        int maxi = 0;
        for(int i=1;i<=n;i++){
            if(dist[i] == INT_MAX) return -1;
            maxi = max(maxi,dist[i]);
        }
        return maxi;
    }
};
