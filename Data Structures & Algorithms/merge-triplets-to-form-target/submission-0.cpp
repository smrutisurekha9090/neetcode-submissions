class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool a = false;
        bool b = false;
        bool c = false;
        for(auto &it:triplets){
            if( it[0] > target[0] ||it[1] > target[1] || it[2] > target[2] ){
                continue;
            }
            if(it[0] == target[0]) a=true;
            if(it[1] == target[1]) b=true;
            if(it[2] == target[2]) c=true;

        }
        return a && b && c;
    }
};
