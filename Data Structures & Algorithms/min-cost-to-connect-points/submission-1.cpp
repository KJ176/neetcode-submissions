class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j = i + 1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = abs(x1 - x2) + abs(y1 - y2);
                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited(n, false);
        int count = 0, res = 0;
        
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [w, u] = pq.top(); pq.pop();
            if (visited[u]) continue;
            visited[u] = true;
            count++;
            res += w;
            for(auto& [wt, v] : adj[u]) {
                if (visited[v]) continue;
                pq.push({ wt, v });
            }
        }
        return res;
    }
};
