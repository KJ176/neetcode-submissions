class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int minPrice = prices[0];
        for(int price: prices) {
            minPrice = min(minPrice, price);
            res = max(res, price - minPrice);
        }
        return res;
    }
};
