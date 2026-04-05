class MinStack {
public:

    stack<long long int> st;
    long long int minVal = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) {
            minVal = val;
            st.push(val);
        } else {
            if(val < minVal) {
                st.push((long long)2*val - minVal);
                // st.push((2LL * val) - minVal)
                minVal = val;
            } else {
                st.push(val);
            }
        }
    }
    
    void pop() {
        if (st.top() < minVal) {
            // pushed_value = 2 * actual value (also current minVal) - oldMinVal
            // => oldMinVal = 2 * minVal - pushed_value ie, st.top()
            minVal = 2*minVal - st.top();
        }
        st.pop();
    }
    
    int top() {
        if (st.top() < minVal) {
            return minVal;
        }
        return st.top();
    }
    
    int getMin() {
        return minVal;
    }
};
