class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        for(string str : strs) {
            vector<int> freq(26, 0);
            for(char c : str) {
                freq[c - 'a']++;
            }
            string key = "";
            for(int val : freq) {
                key += to_string(val) + ',';
            }
            mpp[key].push_back(str);
        }
        
        vector<vector<string>> res;
        for(auto& it : mpp) {
            res.push_back(it.second);
        }
        return res;
    }
};
