class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mpp;
        for(string s : strs) {
            vector<int> cnt(26, 0);
            for(char c : s) {
                cnt[c - 'a']++;
            }
            string key = "";
            for(int val : cnt) {
                key += to_string(val) + ",";
            }
            mpp[key].push_back(s);
        }
        for(auto& it : mpp) {
            res.push_back(it.second);
        }
        return res;
    }
};
