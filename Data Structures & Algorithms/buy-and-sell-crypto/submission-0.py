class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxP = 0
        length = len(prices)
        buy = prices[0]
        for i in range(1, length):
            sell = prices[i]
            if buy > sell:
                buy = sell
            else:
                maxP = max(maxP, sell-buy)
        return maxP