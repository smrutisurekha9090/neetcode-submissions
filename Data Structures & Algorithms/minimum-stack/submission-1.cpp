class MinStack {
public:
//using 2 stack tc-o(1) sc-o(n)
    stack<int>s;
    stack<int>ss;
    MinStack() {
        
    }
    
    void push(int val) {
       s.push(val);
       if(ss.empty() || ss.top()>=val){
            ss.push(val);
       } 
    }
    
    void pop() {
        if(s.top()==ss.top()){
            ss.pop();
        }
        s.pop();
    }
    
    int top() {
        if(s.empty()) return -1;
        else return s.top();       
    }
    
    int getMin() {
        if(ss.empty()) return -1;
        else return ss.top();   
    }
};
