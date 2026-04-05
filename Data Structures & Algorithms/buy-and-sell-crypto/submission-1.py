class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        res = 0
        minval = prices[0]
        for i in range(1, len(prices)):
            minval = min(prices[i], minval)
            profit = prices[i] - minval
            res = max(profit, res)
        return res