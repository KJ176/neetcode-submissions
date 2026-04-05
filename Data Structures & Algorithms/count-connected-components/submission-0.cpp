class Solution {
private:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visit) {
        visit[node] = true;
        for(int nei: adj[node]) {
            if (!visit[nei]) {
                dfs(nei, adj, visit);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visit(n, false);

        int res = 0;
        for(int node = 0; node < n; node++) {
            if (!visit[node]) {
                dfs(node, adj, visit);
                res++;
            }
        }
        return res;
    }
};
