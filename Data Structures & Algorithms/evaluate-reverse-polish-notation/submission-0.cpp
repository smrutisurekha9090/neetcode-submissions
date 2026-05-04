static unordered_set<string>operations({"+","-","*","/"});
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(auto token:tokens){
            if(operations.find(token)==operations.end()){
                s.push(stoi(token));
            }else{
                int b=s.top();
                s.pop();
                int a=s.top();
                s.pop();
                if(token == "+") s.push(a+b);
                else if(token == "-") s.push(a-b);
                else if(token == "*") s.push(a*b);
                else if(token == "/") s.push(a/b);
            }
        }
        return s.top();
    }
};
