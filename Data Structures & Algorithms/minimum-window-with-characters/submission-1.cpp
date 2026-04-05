class Solution {
public:
    string minWindow(string s, string t) {
        if(t == "") return t;

        unordered_map<char, int> mapt, window;
        for(char c: t) {
            mapt[c]++;
        }

        int have = 0, need = mapt.size();
        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;
        int l = 0;
        for(int r = 0; r<s.size(); r++) {
            char c = s[r];
            window[c]++;
            if(mapt.count(c) && window[c] == mapt[c]) {
                have++;
            }
            while(have == need) {
                if ((r-l+1) < resLen) {
                    resLen = r-l+1;
                    res = {l, r};
                }
                window[s[l]]--;
                if(mapt.count(s[l]) && window[s[l]] < mapt[s[l]]) {
                    have--;
                }
                l++;
            }
        }
        if (resLen == INT_MAX)
            return "";
        return s.substr(res.first, resLen);
    }
};
