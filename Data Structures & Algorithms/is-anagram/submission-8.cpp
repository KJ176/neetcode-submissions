class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mpp;
        for(char c : s) {
            mpp[c] += 1;
        }
        for(char c : t) {
            mpp[c] -= 1;
        }
        for(auto& [c, cnt] : mpp) {
            if (cnt != 0) {
                return false;
            }
        }
        return true;
    }
};
