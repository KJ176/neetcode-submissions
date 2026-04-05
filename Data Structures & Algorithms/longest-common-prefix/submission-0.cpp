class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string word1 = strs[0], word2 = strs.back();
        int length = min(word1.size(), word2.size());
        string res = "";
        for(int i = 0; i < length; i++) {
            if (word1[i] != word2[i]) {
                return res;
            }
            res += word1[i];
        }
        return res;
    }
};