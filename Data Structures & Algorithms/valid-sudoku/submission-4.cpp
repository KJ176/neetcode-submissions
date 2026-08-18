class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, set<char>> rowMap;
        unordered_map<int, set<char>> colMap;
        map<pair<int, int>, set<char>> boxMap;

        for(int row = 0; row < 9; row++) {
            for(int col = 0; col < 9; col++) {
                char val = board[row][col];

                if (val == '.') continue;
                
                pair<int, int> boxKey = {row/3, col/3};

                if (rowMap[row].find(val) != rowMap[row].end() || 
                    colMap[col].find(val) != colMap[col].end() ||
                    boxMap[boxKey].find(val) != boxMap[boxKey].end()
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
