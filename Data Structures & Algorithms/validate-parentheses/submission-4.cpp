class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s) {
            switch (c) {
                case '(': 
                case '{': 
                case '[':
                    st.push(c); break;
                case '}':
                    if (!st.empty() and st.top() == '{') {
                        st.pop(); break;
                    } else return false;
                case ')':
                    if (!st.empty() and st.top() == '(') {
                        st.pop(); break;
                    } else return false;
                case ']':
                    if (!st.empty() and st.top() == '[') {
                        st.pop(); break;
                    } else return false;
            }
        }
        return st.empty();
    }
};
