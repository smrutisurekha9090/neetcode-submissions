class DisjointSet {
    vector<int> rank, parent;

   public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int findUPar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
};
class Solution {
   public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;

        DisjointSet ds(n);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            if (ds.findUPar(u) == ds.findUPar(v)) return false;
            ds.unionByRank(u, v);
        }
        return true;
    }
};
