class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() and temperatures[st.top()] < temperatures[i]) {
                int days = i - st.top(); 
                res[st.top()] = days;
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
