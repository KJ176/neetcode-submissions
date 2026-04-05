class MinStack {

private:
    stack<pair<int, int>> st;
    int minVal;
public:

    MinStack() {

    }
    
    void push(int val) {
        if(st.empty()) {
            st.push({val, val});
        } else {
            minVal = min(val, st.top().second);
            st.push({val, minVal});
        }
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
