class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int res = 0;

        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
        queue<pair<int, int>> q;
        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if (grid[r][c] == 1) {
                    q.push({r, c});
                    visited[r][c] = true;
                    r = ROWS;
                    break;
                }
            }
        }

        int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!q.empty()) {
            auto [r, c] = q.front(); q.pop();

            for(int i = 0; i < 4; i++) {
                int nr = r + directions[i][0];
                int nc = c + directions[i][1];
                if (nr < 0 or nr == ROWS or nc < 0 or nc == COLS or grid[nr][nc] == 0) {
                    res++;
                } else if (!visited[nr][nc]){
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }

        return res;
    }
};