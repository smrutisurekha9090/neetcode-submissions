class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>>v;
        for(int i=0;i<position.size();i++){
            double time = (double) (target-position[i])/speed[i];
            v.push_back({position[i],time});
        }

        sort(v.begin(),v.end(),greater<pair<int,double>>());
        stack<double>st;
        for(auto it:v){
            double time =it.second;
            if(st.empty() || time> st.top()){
                st.push(time);
            }
        }
        return st.size();
    }
};
