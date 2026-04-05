class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int maxLen = 0;

        int n = s.size();
        int l, r;
        for(int i = 0; i < n; i++) {
            // Odd lengths
            l = i, r = i;
            while (l >= 0 and r < n and s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    maxLen = r - l + 1;
                    res = s.substr(l, maxLen);
                }
                l--; r++;
            }

            // Even lenghts
            l = i, r = i + 1;
            while (l >= 0 and r < n and s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    maxLen = r - l + 1;
                    res = s.substr(l, maxLen);
                }
                l--; r++;
            }
        }
        return res;
    }
};
