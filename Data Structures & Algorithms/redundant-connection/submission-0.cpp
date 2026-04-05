class DSU {
    vector<int> parent, size;
public:
    DSU(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int findParent(int node) {
        if(node != parent[node]) {
            parent[node] = findParent(parent[node]);
        }
        return parent[node];
    }
    bool unionSet(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv) return false; 
        // This means they both have the same parent already and 
        // we are trying to add an edge between them
        if (pu > pv) {
            swap(pu, pv);
        }
        parent[pu] = pv;
        size[pu] += size[pv];
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);
        for(auto &e : edges) {
            if (!dsu.unionSet(e[0], e[1])) {
                return {e[0], e[1]};
            }
        }
        return {};
    }
};
