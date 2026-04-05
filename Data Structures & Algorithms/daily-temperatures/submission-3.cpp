class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> st;
        int l = 0;
        for(int l = 0; l<n; l++) {
            while(!st.empty() && temperatures[st.top()] < temperatures[l]) {
                res[st.top()] = l - st.top();
                st.pop();
            }
            st.push(l);
        }
        return res;
    }
};
