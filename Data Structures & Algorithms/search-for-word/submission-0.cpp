class Solution {
public:
    int ROWS, COLS;
    vector<vector<bool>> visited;
    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();
        visited = vector<vector<bool>> (ROWS, vector<bool>(COLS, false));

        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if (backtrack(board, word, r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool backtrack(vector<vector<char>>& board, string word, int r, int c, int i) {
        if (i == word.size()) return true;
        if (r < 0 or r == ROWS or c < 0 or c == COLS || board[r][c] != word[i] || visited[r][c]) {
            return false;
        }
        visited[r][c] = true;
        bool res = backtrack(board, word, r - 1, c, i + 1) 
            || backtrack(board, word, r, c - 1, i + 1)
            || backtrack(board, word, r + 1, c, i + 1)
            || backtrack(board, word, r, c + 1, i + 1);
        visited[r][c] = false;
        return res; 
    }
};
