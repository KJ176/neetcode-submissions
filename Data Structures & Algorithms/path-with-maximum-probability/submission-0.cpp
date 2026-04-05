class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double p = succProb[i];
            adj[u].push_back({v, p});
            adj[v].push_back({u, p});
        }

        vector<double> dist(n, 0.0);
        dist[start_node] = 1.0;

        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});

        while(!pq.empty()) {
            auto [p, u] = pq.top(); pq.pop();
            if (u == end_node) return p;

            if (p < dist[u]) continue;
            for(auto& [v, prob] : adj[u]) {
                if (dist[u] * prob > dist[v]) {
                    dist[v] = dist[u] * prob;
                    pq.push({ dist[v], v });
                }
            }
        }
    return 0.0;
    }
};