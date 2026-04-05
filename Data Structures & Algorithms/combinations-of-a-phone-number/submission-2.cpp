// class Solution {
// private:
//     unordered_map<char, string> mpp = {
//         {'2', "abc"},
//         {'3', "def"},
//         {'4', "ghi"},
//         {'5', "jkl"},
//         {'6', "mno"},
//         {'7', "pqrs"},
//         {'8', "tuv"},
//         {'9', "wxyz"}
//     };
//     vector<string> res;
//     void backtrack(string &digits, int idx, string &cur) {
//         if (idx == digits.size()) {
//             res.push_back(cur);
//             return;
//         }
//         char digit = digits[idx];
//         string letters = mpp[digit];
//         for (char c : letters) {
//             cur.push_back(c);
//             backtrack(digits, idx + 1, cur);
//             cur.pop_back();
//         }
//     }
    
// public:
//     vector<string> letterCombinations(string digits) {
//         if (digits.empty()) return {};
//         string cur = "";
//         backtrack(digits, 0, cur);
//         return res;
//     }
// };
class Solution {
public:
    vector<string> res;
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "qprs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;
        backtrack(0, "", digits);
        return res;
    }

    void backtrack(int i, string curStr, string &digits) {
        if (curStr.size() == digits.size()) {
            res.push_back(curStr);
            return;
        }
        string chars = digitToChar[digits[i] - '0'];
        for (char c : chars) {
            backtrack(i + 1, curStr + c, digits);
        }
    }
};