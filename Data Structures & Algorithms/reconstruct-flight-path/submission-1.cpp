class Solution {
private:
    vector<string> res;
    int targetLen;

    bool dfs(const string& src, unordered_map<string, vector<string>>& adj) {
        if (res.size() == targetLen) {
            return true;
        }
        if (adj.find(src) == adj.end()) {
            return false;
        }

        vector<string> temp = adj[src];  // copy to preserve iteration order
        for (int i = 0; i < temp.size(); i++) {
            string v = temp[i];
            adj[src].erase(adj[src].begin() + i); // use this ticket
            res.push_back(v);
            if (dfs(v, adj)) return true;
            // backtrack
            adj[src].insert(adj[src].begin() + i, v);
            res.pop_back();
        }
        return false;
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;

        sort(tickets.begin(), tickets.end());
        for (auto& ticket : tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }

        res = {"JFK"};
        targetLen = tickets.size() + 1;

        dfs("JFK", adj);
        return res;
    }
};
