class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int n= matrix.size();
        int m= matrix[0].size();
        int right = m-1,bottom = n-1,left = 0,top =0;
        int direction =0;
        while(left <= right && top <= bottom) {
            if(direction ==0){
                for(int i=left;i<=right;i++){
                    ans.push_back(matrix[top][i]);
                }
                direction =1;
                top++;
            }
            else if(direction ==1){
                for(int i=top;i<=bottom;i++){
                    ans.push_back(matrix[i][right]);
                }
                direction =2;
                right--;
            }
              else if(direction ==2){
                for(int i=right;i>=left;i--){
                    ans.push_back(matrix[bottom][i]);
                }
                direction =3;
                bottom--;
            }
              else if(direction ==3){
                for(int i=bottom;i>=top;i--){
                    ans.push_back(matrix[i][left]);
                }
                direction =0;
                left++;
            }
        }
        return ans;
    }
};
