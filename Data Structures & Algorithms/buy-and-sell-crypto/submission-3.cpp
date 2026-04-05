class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int minVal = prices[0];
        for (int price: prices) {
            int profit = price - minVal;
            res = max(res, profit);
            minVal = min(minVal, price);
        }
        return res;
    }
};
