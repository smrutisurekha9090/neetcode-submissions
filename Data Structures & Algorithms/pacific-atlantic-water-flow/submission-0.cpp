class Solution {
public:
    int n;
    int m;
    void dfs(vector<vector<int>>& heights ,int row ,int col ,vector<vector<int>>& visited){
        visited[row][col] = 1;

        int dRow[] = {-1,1,0,0};
        int dCol[] = {0,0,-1,1};

        for(int i=0;i<4;i++){
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];

            if(nRow >=0 && nRow < n &&
               nCol >=0 && nCol < m &&
               !visited[nRow][nCol] &&
               heights[nRow][nCol] >=  heights[row][col]){
                dfs(heights,nRow,nCol,visited);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        vector<vector<int>> pacific(n,vector<int>(m,0));
        vector<vector<int>> atlantic(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            dfs(heights,i,0,pacific);
            dfs(heights,i,m-1,atlantic);
        }
        for(int j=0;j<m;j++){
            dfs(heights,0,j,pacific);
            dfs(heights,n-1,j,atlantic);
        }

        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;

    }
};
