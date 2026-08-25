class Solution {
public:
    int calculator(int x, int y, char operand) {
        switch(operand) {
            case '+': return x + y; break;
            case '-': return x - y; break;
            case '*': return x * y; break;
            case '/': return x / y; break;
        }
        return 0;

    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_set<string> operands = {"+", "-", "*", "/"};

        for(string s : tokens) {
            if (operands.count(s) > 0) {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                int res = calculator(a, b, s[0]);
                st.push(res);
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
