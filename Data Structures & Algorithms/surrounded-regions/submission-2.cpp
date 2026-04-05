class Solution {
private:
    int ROWS, COLS;
    int directions[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

    void bfs(vector<vector<char>>& board) {
        queue<pair<int, int>> q;
        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if ((r == 0 or r == ROWS - 1 or c == 0 or c == COLS - 1) and board[r][c] == 'O') {
                    q.push({r, c});
                    board[r][c] = 'T';
                }
            }
        }
        while(!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for(int i = 0; i < 4; i++) {
                int nr = r + directions[i][0];
                int nc = c + directions[i][1];
                if (nr >=0 and nr < ROWS and nc >= 0 and nc < COLS and board[nr][nc] == 'O') {
                    q.push({nr, nc});
                    board[nr][nc] = 'T';
                }
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        ROWS = board.size();
        COLS = board[0].size();

        bfs(board);
        
        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                } else if (board[r][c] == 'T') {
                    board[r][c] = 'O';
                }
            }
        }
    }
};
