class DisjointSet{
    vector<int>rank,parent;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findUParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUParent(parent[node] );
    }

    bool unionByRank(int u,int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u == ulp_v) return false; 

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }else{
            parent[ulp_u] = ulp_v;
            rank[ulp_v]--;
        }
        return true;
    }

};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        int components = n;
        for(auto &e:edges){
            int u = e[0];
            int v = e[1];

            if(ds.unionByRank(u,v)){
                components--;
            }
        }
        return components;
    }
};
