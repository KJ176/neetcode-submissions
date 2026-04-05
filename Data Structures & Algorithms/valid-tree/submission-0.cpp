class Solution {
private:
    unordered_set<int> visit;
    bool dfs(int node, int parent, vector<vector<int>>& adj) {
        if(visit.count(node)) {
            return false;
        }
        visit.insert(node);
        for(int neigh: adj[node]) {
            if (neigh == parent) {
                continue;
            }
            if (!dfs(neigh, node, adj)) {
                return false;
            }
        } 
        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }
        vector<vector<int>> adj(n);
        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        if (!dfs(0, -1, adj)) {
            return false;
        }

        return visit.size() == n;
    }
};
