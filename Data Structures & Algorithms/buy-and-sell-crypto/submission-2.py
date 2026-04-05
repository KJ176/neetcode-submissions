class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        res = 0
        minval = prices[0]
        for i in range(1, len(prices)):
            profit = prices[i] - minval
            res = max(profit, res)
            minval = min(prices[i], minval)
        return res