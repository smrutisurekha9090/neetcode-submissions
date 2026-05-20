class Solution {
public:
    //PRIM'S ALGO (MST)
    int manhattanDistance(vector<int>&p1, vector<int>&p2){
        return abs(p1[0]-p2[0]) + abs(p1[1]-p2[1]);  
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>>pq;
        vector<int>vis(n,0);
        pq.push({0,0});
        int sum =0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int wt = it.first;
            int node = it.second;

            if(vis[node] == 1) continue;
            vis[node] =1;
            sum +=wt;

            for(int adjNode=0 ; adjNode < n ; adjNode++){
                if(!vis[adjNode]){
                    int distance = manhattanDistance(points[node],points[adjNode]);
                    pq.push({distance,adjNode});
                }
            }

        }
        return sum;
    }
};
