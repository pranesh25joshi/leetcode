class MinStack {
public:
    stack<int> stk;
    stack<int> minstk;
    MinStack() {
        
    }
    
    void push(int val) {
        minstk.push(val);
    }
    
    void pop() {
        minstk.pop();
    }
    
    int top() {
        return minstk.top();
    }
    
    int getMin() {
        int m;
        m = minstk.top();
        while(!minstk.empty()){
            stk.push(minstk.top());
            m = min(m, minstk.top());
            minstk.pop();
        }
        while(!stk.empty()){
            minstk.push(stk.top());
            stk.pop();  
        }

        return m;

    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */