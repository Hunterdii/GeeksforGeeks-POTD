class Solution:
    def findWays(self, n):
        if n & 1: return 0
        n >>= 1
        res = 1
        for i in range(n):
            res = res * (2 * n - i) // (i + 1)
        return res // (n + 1)
