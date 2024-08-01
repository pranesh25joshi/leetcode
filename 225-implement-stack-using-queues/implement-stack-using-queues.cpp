class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        if( q1.empty() && q2.empty()){
            return -1;
        }
        if( !q1.empty()){
            while(q1.size() != 1){
                int y = q1.front();
                q1.pop();
                q2.push(y);
            }
            int y = q1.front();
            q1.pop();
            return y;
        }
        if( !q2.empty()){
            while(q2.size() != 1){
                int y = q2.front();
                q2.pop();
                q1.push(y);
            }
            int y = q2.front();
            q2.pop();
            return y;
        }
        return -1;
    }
    
    int top() {
        if(!q1.empty()){
            return q1.back();
        }
        if(!q2.empty()){
            return q2.back();
        }
        return -1;
    }
    
    bool empty() {
        if(q1.empty() && q2.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */