class MinStack {
public:
    stack<int> st;
    stack<int> minSt;
    int minElement = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minSt.empty() || minSt.top()>=val){
            minSt.push(val);
        }
    }
    
    void pop() {
        if(st.top() == minSt.top()){
            minSt.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
