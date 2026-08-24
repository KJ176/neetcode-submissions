class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int res = 0;
        int l = 0, maxf = 0;
        for(int r = 0; r < s.size(); r++) {
            char c = s[r];
            count[c - 'A']++;
            maxf = max(maxf, count[c - 'A']);
            while((r - l + 1) - maxf > k) {
                count[s[l] - 'A']--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
