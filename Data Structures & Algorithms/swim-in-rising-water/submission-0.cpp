class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        pq.push({grid[0][0], 0, 0});
        visited[0][0] = 1;

        while(!pq.empty()) {
            vector<int> cur = pq.top(); pq.pop();
            int t = cur[0], r = cur[1], c = cur[2];
            if (r == n - 1 and c == n - 1) {
                return t;
            }
            for(auto& dir: directions) {
                int neiR = r + dir[0], neiC = c + dir[1];
                if (neiR < 0 or neiR == n or neiC < 0 or neiC == n or visited[neiR][neiC]) {
                    continue;
                }
                visited[neiR][neiC] = 1;
                pq.push({max(t, grid[neiR][neiC]), neiR, neiC});
            }
        }

        return pow(n, 2);
    }
};
