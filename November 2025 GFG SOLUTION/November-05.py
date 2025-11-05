class Solution:
    def minSquares(self, n):
        s = int(n ** 0.5)
        if s * s == n: return 1
        for i in range(1, int(n ** 0.5) + 1):
            r = int((n - i * i) ** 0.5)
            if r * r == n - i * i: return 2
        while n % 4 == 0: n //= 4
        return 4 if n % 8 == 7 else 3
