class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev2 = 0, prev1 = 0;
        int res;
        for(int i = 2; i <= n; i++) {
            res = min(
                prev2 + cost[i-2],
                prev1 + cost[i-1]
            );
            prev2 = prev1;
            prev1 = res;
        }
        return res;
    }
};
