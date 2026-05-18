class Solution {
public:
    
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n == 0) return ;

        //put all the gates into the queue
        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]== 0){
                    q.push({i,j});
                }
            }
        }

        int delRow[] = {-1,1,0,0};
        int delCol[] = {0,0,-1,1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;

            q.pop();
            for(int i=0;i<4;i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if(nRow >= 0 && nRow < n && nCol >=0 && nCol < m && grid[nRow][nCol] == 2147483647){
                    grid[nRow][nCol] = grid[row][col] +1;
                    q.push({nRow,nCol});
                }
            }
        }
         
    }
};
