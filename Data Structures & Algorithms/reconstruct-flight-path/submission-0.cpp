class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;
        for(const auto& ticket : tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }
        for(auto& [src, destinations] : adj) {
            sort(destinations.rbegin(), destinations.rend());
        }

        vector<string> res;
        stack<string> st;
        st.push("JFK");

        while(!st.empty()) {
            string cur = st.top();
            if(adj[cur].empty()) {
                res.push_back(cur);
                st.pop();
            } else {
                string next = adj[cur].back();
                adj[cur].pop_back();
                st.push(next);
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
