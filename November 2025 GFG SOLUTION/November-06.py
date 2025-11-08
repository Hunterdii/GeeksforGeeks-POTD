class Solution:
    def numberOfWays(self, n):
        if n <= 1: return 1
        a, b = 1, 1
        for _ in range(n - 1):
            a, b = b, a + b
        return b
