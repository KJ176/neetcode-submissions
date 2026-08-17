class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;

        for(string &str : strs) {
            vector<int> cnt(26, 0);
            for(char &c : str) {
                cnt[c - 'a']++;
            }
            string stringifiedCnt = "";
            for(int val : cnt) {
                stringifiedCnt += to_string(val) + ",";
            }
            mpp[stringifiedCnt].push_back(str);
        }

        vector<vector<string>> res;
        for(auto &it : mpp) {
            res.push_back(it.second);
        }
        return res;
    }
};
