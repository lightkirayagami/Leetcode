// Last updated: 27/04/2026, 21:50:28
class MinStack {
public:
stack<pair<int,int>>st;
    MinStack() {
        
    }
    
    void push(int val) {

        if(st.empty())
        {
            st.push({val,val});
            return;
        }

        int newmin=min(val,st.top().second);
        st.push({val,newmin});
        
    }
    
    void pop() {

        st.pop();
        
    }
    
    int top() {

        return st.top().first;
        
    }
    
    int getMin() {
        return st.top().second;
        
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