class MinStack {
public:
    stack<pair<int, int>> st;
    int minVal = INT_MAX;
    MinStack() {
    }
    
    void push(int val) {
        minVal = min(minVal, val);
        st.push({val, minVal});
    }
    
    void pop() {
        st.pop();
        if (!st.empty()) minVal = st.top().second;
        else minVal = INT_MAX;
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
