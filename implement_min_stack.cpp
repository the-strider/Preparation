class MinStack {
public:
    stack < int > st1;
    stack < int > st2;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        st1.push(x);
        if(st2.empty()) {
            st2.push(x);
        } else {
            st2.push(min(x, st2.top()));
        }
    }
    
    void pop() {
        st1.pop();
        st2.pop();
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */