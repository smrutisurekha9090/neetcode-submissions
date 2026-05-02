class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        for(auto it:s){
            char top1;
            if(st.empty()){
                top1= '#';
            }else{
                top1=st.top();
            }
            if(top1 == '(' && it == ')'){
                st.pop();
            }else if(top1 == '{' && it == '}'){
                st.pop();
            }else if(top1 == '[' && it == ']'){
                st.pop();
            }else{
                st.push(it);
            }
        }
        return st.empty();
    }
};
