class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        queue<pair<int, int>> q;
        for(int i = 0; i< ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while(!q.empty()) {
            auto [row, col] = q.front(); q.pop();
            for(int i = 0; i < 4; i++) {
                int nr = row + directions[i][0];
                int nc = col + directions[i][1];
                if (nr < 0 or nr == ROWS or nc < 0 or nc == COLS or grid[nr][nc] != INT_MAX) {
                    continue;
                }
                grid[nr][nc] = grid[row][col] + 1;
                q.push({nr, nc});
            }
        }
    }
};
