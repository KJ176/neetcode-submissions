class Solution {
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
private:
    int res = 0;
    int ROWS, COLS;
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 or r == ROWS or c < 0 or c == COLS or grid[r][c] == 0) {
            return 0;
        }
        int area = 1;
        grid[r][c] = 0;
        
        for(int i = 0; i < 4; i++) {
            area += dfs(grid, r + directions[i][0], c + directions[i][1]);
        }

        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c<COLS; c++) {
                if (grid[r][c] == 1) {
                    int area = dfs(grid, r, c);
                    res = max(res, area);
                }
            }
        }
        return res;
    }
};
