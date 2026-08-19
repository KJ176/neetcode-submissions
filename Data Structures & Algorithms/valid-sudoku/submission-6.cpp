class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rowMap, colMap;
        map<pair<int, int>, unordered_set<char>> boxMap;
        for(int row = 0; row < 9; row++) {
            for(int col = 0; col < 9; col++) {
                char val = board[row][col];
                if (val == '.') continue;
                pair<int, int> boxKey = {row/3, col/3};
                if (
                    rowMap[row].count(val) > 0 ||
                    colMap[col].count(val) > 0 ||
                    boxMap[boxKey].count(val) > 0
                ) {
                    return false;
                }
                rowMap[row].insert(val);
                colMap[col].insert(val);
                boxMap[boxKey].insert(val);
            }
        }
        return true;
    }
};
