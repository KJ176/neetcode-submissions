class DSU {
    vector<int> parent, size;
public:
    DSU(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0; i <= n; i++) {
            parent[i]=i;
        }
    }

    int findParent(int node) {
        if (node == parent[node]) return node;
        parent[node] = findParent(parent[node]);
        return parent[node];
    }

    bool unionSet(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv) {
            return false;
        }
        if (size[pu] > size[pv]) {
            swap(pu, pv);
        }
        parent[pu] = pv;
        size[pv] += size[pu];
        return true;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int res = n;
        for(auto &edge: edges) {
            if (dsu.unionSet(edge[0], edge[1])) {
                res--;
            }
        }
        return res;
    }
};
