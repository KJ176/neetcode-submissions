class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mapt, window;
        for(char c : t) {
            mapt[c]++;
        }

        int have = 0, need = mapt.size();
        pair<int, int> resWindow = {-1, -1};
        int resLen = INT_MAX;
        int l = 0;

        for(int r = 0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;
            if (mapt.count(c) and mapt[c] == window[c]) {
                have++;
            }
            while(have == need) {
                int curLen = r - l + 1;
                if (curLen < resLen) {
                    resLen = curLen;
                    resWindow = {l, r};
                }
                window[s[l]]--;
                if (mapt.count(s[l]) and mapt[s[l]] > window[s[l]]) have--;
                l++;
            }
        }

        if (resLen == INT_MAX) return "";
        return s.substr(resWindow.first, resLen);
    }
};
