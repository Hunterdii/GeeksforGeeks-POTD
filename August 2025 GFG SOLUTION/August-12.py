class Solution:
    def minMaxCandy(self, prices, k):
        prices.sort()
        n, min_, max_ = len(prices), 0, 0
        i, rem = 0, n
        while i < rem:
            min_ += prices[i]; i += 1; rem -= k
        j, idx = n - 1, -1
        while j > idx:
            max_ += prices[j]; j -= 1; idx += k
        return [min_, max_]
