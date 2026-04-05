class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        int time = 0;

        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if (grid[r][c] == 1) {
                    fresh++;
                } else if (grid[r][c] == 2) {
                    q.push({r, c});
                }
            }
        }

        int directions[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        while(fresh > 0 and !q.empty()) {
            int length = q.size();
            for(int i = 0; i < length; i++) {
                auto [r, c] = q.front(); q.pop();
                for(int i = 0; i < 4; i++) {
                    int nr = r + directions[i][0];
                    int nc = c + directions[i][1];
                    if (nr >= 0 and nr < ROWS and nc >= 0 and nc < COLS and grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
            time++;
        }
        return fresh > 0 ? -1 : time;
    }
};
