class Solution {
private:
    vector<vector<string>> res;

    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++; r--;
        }
        return true;
    }

    void backtrack(string s, vector<string> &partition) {
        if (s.empty()) {
            res.push_back(partition);
            return;
        }
        for(int i = 0; i < s.size(); i++) {
            string substring = s.substr(0, i + 1);
            if (isPalindrome(substring)) {
                partition.push_back(substring);
                backtrack(s.substr(i + 1), partition);
                partition.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<string> partition;
        backtrack(s, partition);
        return res;
    }
};
