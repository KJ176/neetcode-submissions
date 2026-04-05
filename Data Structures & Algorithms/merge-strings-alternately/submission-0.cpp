class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l1 = word1.size(), l2 = word2.size();
        int i = 0, j = 0;
        string res = "";
        while (i < l1 and j < l2) {
            res += word1[i++];
            res += word2[j++];
        }
        while (i < l1) {
            res += word1[i++];
        }
        while (j < l2) {
            res += word2[j++];
        }
        return res;
    }
};