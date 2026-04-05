class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        int count = 1;
        while (l < r) {
            if (s[l] == s[r]) {
                l++; r--;
            } else if (count--){
                if (s[l] == s[r - 1]) {
                    r--;
                } else if (s[l + 1] == s[r]) {
                    l++;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }
};