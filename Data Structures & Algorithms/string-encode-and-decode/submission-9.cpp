class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(string &s : strs) {
            int len = s.size();
            res += to_string(len) + '#' + s;
        }

        return res;
    }
    // 5#Hello5#World
    // ij

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        int j = i + 1;
        while (j <= s.size()) {
            while(s[j] != '#') j++;
            int length = stoi(s.substr(i, j-i));

            i = j + 1;
            res.push_back(s.substr(i, length));
            i = i + length;
            j = i + 1;
        }
        return res;
    }
};
