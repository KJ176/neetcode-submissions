class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int, int>> st;
        int res = 0;

        for(int i = 0; i < n; i++) {
            int start = i; // Start point that the current bar can support
            while(!st.empty() && st.top().second > heights[i]) {
                pair<int, int> top = st.top();
                int index = top.first; int height = top.second;
                res = max(res, height * (i - index));
                start = index; // Current bar can support more to the left now since its shorter
                st.pop();
            }
            st.push({start, heights[i]});
        }
        while(!st.empty()) {
            pair<int, int> top = st.top();
            int index = top.first; int height = top.second;
            res = max(res, height * (n - index));
            st.pop();
        }
        return res;
    }
};
