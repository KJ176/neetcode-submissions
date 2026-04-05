class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int val : asteroids) {
            bool destroyed = false;

            while (!st.empty() && st.top() > 0 && val < 0) {
                int top = st.top();
                if (top < (-1 * val)) {
                    st.pop();
                    continue;
                } else if (top == (-1 * val)) {
                    st.pop();
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break;
                }
            }
            if (!destroyed) {
                st.push(val);
            }
        }
        int n = st.size();
        vector<int> res(n, 0);
        for(int i = n - 1; i >= 0; i--) {
            res[i] = st.top(); st.pop();
        };

        return res;
    }
};