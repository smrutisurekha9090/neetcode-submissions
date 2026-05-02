class MinStack {
public:

    stack<long long>s;
    long long minElement = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            minElement = val;
        }else if(val >= minElement ){
            s.push(val);
        }else if(val < minElement){
            s.push(2LL * val - minElement);
            minElement = val;
        }
    }
    
    void pop() {
         if(s.empty()){
            return;
        }else if(s.top() >= minElement ){
            s.pop();
        }else if(s.top() < minElement){
            minElement = (2LL * minElement - s.top());
            s.pop();
        }
    }
    
    int top() {
        if(s.empty()) return -1;
        else if(s.top() >= minElement){
            return s.top();
        }else
            return minElement;
    }
    
    int getMin() {
        if(s.empty()) return -1;
        else return minElement;
    }
};
