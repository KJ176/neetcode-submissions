class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> mapper = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };

        for(char c : s) {
           if(mapper.count(c) > 0) {
                if(!st.empty() && st.top() == mapper[c]) {
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
