class Solution {
private:
    int directions[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int ROWS, COLS;
    void bfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, queue<pair<int, int>> q) {
        while(!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            ocean[r][c] = true;
            for(int i = 0; i < 4; i++) {
                int nr = r + directions[i][0];
                int nc = c + directions[i][1];
                if (nr >= 0 and nr < ROWS and nc >= 0 and nc < COLS and !ocean[nr][nc] and heights[nr][nc] >= heights[r][c]) {
                    q.push({nr, nc});
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();
        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));

        queue<pair<int, int>> pacQueue, atlQueue;

        for(int r = 0; r < ROWS; r++) {
            pacQueue.push({r, 0});
            atlQueue.push({r, COLS - 1});
        }
        for(int c = 0; c < COLS; c++) {
            pacQueue.push({0, c});
            atlQueue.push({ROWS - 1, c});
        }

        bfs(heights, pac, pacQueue);
        bfs(heights, atl, atlQueue);

        vector<vector<int>> res;
        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if (pac[r][c] and atl[r][c]) {
                    res.push_back({r, c});
                }
            }
        }
        return res;
    }
};
