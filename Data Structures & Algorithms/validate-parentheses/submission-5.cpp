class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> mpp;
        mpp.insert({')', '('});
        mpp.insert({'}', '{'});
        mpp.insert({']', '['});

        for(char c : s) {
            if (mpp.count(c) > 0) {
                if (!st.empty() and st.top() == mpp[c]) {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                st.push(c);
            }
        }
        return st.empty();
    }
};
