class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;
        for(int i = 0; i <= k; i++) { // k+2 nodes including src, dest so k+1 iterations
            vector<int> temp = prices;
            for(auto &flight : flights) {
                int s = flight[0], d = flight[1], p = flight[2];
                if (prices[s] == INT_MAX) {
                    continue;
                }
                if (prices[s] + p < temp[d]) {
                    temp[d] = prices[s] + p;
                }
            }
            prices = temp;
        }

        if (prices[dst] == INT_MAX) {
            return -1;
        }
        return prices[dst];
    }
};
