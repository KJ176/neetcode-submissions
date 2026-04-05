class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int, int>> st;
        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            int start = i;
            while(!st.empty() && st.top().second > heights[i]) {
                pair<int, int> top = st.top();
                int index = top.first;
                int height = top.second;

                maxArea = max(maxArea, (i - index) * height);
                start = index;
                st.pop();
            }
            st.push({ start, heights[i]});
        }

        while(!st.empty()) {
            pair<int, int> top = st.top();
            int index = top.first;
            int height = top.second;
            maxArea = max(maxArea, (n - index) * height);
            st.pop();
        }

        return maxArea;
    }
};
