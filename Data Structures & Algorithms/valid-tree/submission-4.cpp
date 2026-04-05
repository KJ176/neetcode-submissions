class DSU {
    vector<int> parent;
    vector<int> size;
    int components;
public:
    DSU(int n) {
        components = n;
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
    int unionNodes(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) {
            return false;
        }
        if (pu < pv) {
            swap(pu, pv);
        }
        parent[pv] = pu;
        size[u] += size[v];
        components--;
        return true;
    }
    int comps () {
        return components;
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n - 1) {
            return false;
        }
        DSU dsu(n);
        for(auto &edge : edges) {
            if (!dsu.unionNodes(edge[0], edge[1])) {
                return false;
            }
        }
        return dsu.comps() == 1;
    }
};
