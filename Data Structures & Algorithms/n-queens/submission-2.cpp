class Solution {
private:
    vector<vector<string>> res;
    unordered_set<int> column;
    unordered_set<int> posDiag;
    unordered_set<int> negDiag;

    void backtrack(int row, int n, vector<string> &board) {
        if (row == n) {
            res.push_back(board);
            return;
        }
        for(int col = 0; col < n; col++) {
            if (column.count(col) || posDiag.count(row + col) || negDiag.count(row - col)) {
                continue;
            }
            column.insert(col);
            posDiag.insert(row+col);
            negDiag.insert(row-col);
            board[row][col] = 'Q';

            backtrack(row + 1, n, board);

            column.erase(col);
            posDiag.erase(row+col);
            negDiag.erase(row-col);
            board[row][col] = '.';
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(0, n, board);
        return res;
    }
};
