class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int minPrice = prices[0];
        int maxPrice = prices[0];
        for(int price: prices) {
            minPrice = min(minPrice, price);
            // maxPrice = max(maxPrice, price);
            res = max(res, price - minPrice);
        }
        return res;
    }
};
