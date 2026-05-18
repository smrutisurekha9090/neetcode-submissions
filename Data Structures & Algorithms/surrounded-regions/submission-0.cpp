class Solution {
public:
    int n;
    int m;
    void dfs(vector<vector<char>>& board,int row, int col,vector<vector<int>>& vis){
        vis[row][col] = 1;

        int dRow[] = {-1,1,0,0};
        int dCol[] = {0,0,-1,1};
        for(int i=0;i<4;i++){
            int nRow = row+dRow[i];
            int nCol = col+dCol[i];

            if(nRow >=0 && nRow <n &&
                nCol >=0 && nCol <m &&
                !vis[nRow][nCol] &&
                board[nRow][nCol] == 'O'){
                dfs(board,nRow,nCol,vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        //first row and last row
        for(int j=0; j<m;j++){
            //fast row
            if(board[0][j] == 'O' && !vis[0][j]){
                dfs(board,0,j,vis);
            }
            //last row
             if(board[n-1][j] == 'O' && !vis[n-1][j]){
                dfs(board,n-1,j,vis);
            }
        }

        //fast col and last col
        for(int i=0;i<n;i++){
            //fast col
            if(board[i][0] == 'O' && !vis[i][0]){
                dfs(board,i,0,vis);
            }
            //last col
             if(board[i][m-1] == 'O' && !vis[i][m-1]){
                dfs(board,i,m-1,vis);
            } 
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]== 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};