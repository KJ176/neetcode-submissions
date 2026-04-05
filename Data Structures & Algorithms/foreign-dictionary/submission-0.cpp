class Solution {
private:
    vector<int> topoSort(vector<vector<int>>& adj, vector<int>& indegree, vector<bool>& present, int k) {
        queue<int> q;
        for(int i = 0; i < 26; i++) {
            if (present[i] && indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> order;
        while(!q.empty()) {
            int node = q.front(); q.pop();
            order.push_back(node);
            for(int nei : adj[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }
        if (order.size() != k) return {};
        return order;
    }
public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> adj(26);
        vector<int> indegree(26, 0);
        vector<bool> present(26, false);
        for(auto &w : words) {
            for(char& c: w) {
                present[c - 'a'] = true;
            }
        }
        for(int i = 0; i < n - 1; ++i) {
            string w1 = words[i];
            string w2 = words[i + 1];
            int len = min(w1.size(), w2.size());
            bool found = false;
            for(int j = 0; j < len; ++j) {
                if (w1[j] != w2[j]) {
                    adj[w1[j] - 'a'].push_back(w2[j] - 'a');
                    indegree[w2[j] - 'a']++;
                    found = true;
                    break;
                }
            }
            if (!found && w1.size() > w2.size()) return "";
        }

        int k = 0;
        for(bool val : present) if (val) k++;

        vector<int> topoRes = topoSort(adj, indegree, present, k);
        string res = "";
        for(int node : topoRes) {
            res.push_back(node + 'a');
        }
        return res;
    }
};
