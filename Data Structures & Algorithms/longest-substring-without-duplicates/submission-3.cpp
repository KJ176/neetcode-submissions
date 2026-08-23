class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, res = 0;
        unordered_set<char> st;
        while(r < s.size()) {
            char c = s[r];
            if (st.count(c) > 0) {
                st.erase(s[l]);
                l++;
            } else {
                while(st.count(c) == 0) {
                    st.insert(c);
                    res = max(res, r - l + 1);
                    r++;
                }
            }
        }
        return res;

    }
};
