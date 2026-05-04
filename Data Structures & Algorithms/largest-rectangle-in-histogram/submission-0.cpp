class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //NSR
        int n=heights.size();
        vector<int>right;
        stack<pair<int,int>>s;
        int pseudoIndex = n;
        for(int i=heights.size()-1;i>=0;i--){
            if(s.empty()){
                right.push_back(pseudoIndex);
            }else if(s.size() >0 &&  s.top().first < heights[i]){
                right.push_back(s.top().second);
            }else if(s.size() >0 &&  s.top().first >= heights[i]){
                while(s.size() >0 &&  s.top().first >= heights[i]){
                    s.pop();
                }
                if(s.size()==0){
                    right.push_back(pseudoIndex);
                }else{
                    right.push_back(s.top().second);
                }
            }
            s.push({heights[i],i});
        }
        reverse(right.begin(),right.end());

        //NSL
        vector<int>left;
        stack<pair<int,int>>st;
        int pseudoIndex1 = -1;
        for(int i=0;i<heights.size();i++){
             if(st.empty()){
                left.push_back(pseudoIndex1);
            }else if(st.size() >0 &&  st.top().first < heights[i]){
                left.push_back(st.top().second);
            }else if(st.size() >0 &&  st.top().first >= heights[i]){
                while(st.size() >0 &&  st.top().first >= heights[i]){
                    st.pop();
                }
                if(st.size()==0){
                    left.push_back(pseudoIndex1);
                }else{
                    left.push_back(st.top().second);
                }
            }
            st.push({heights[i],i});
        }

        int ans =INT_MIN;
        for(int i=0;i<heights.size();i++){
            ans =max((right[i]-left[i]-1)*(heights[i]),ans);
        }
        return ans;

    }
};
