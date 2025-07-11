class Solution:
    def countConsec(self, n: int) -> int:
        a = b = 0
        for i in range(n, 0, -1):
            a, b = a + b, a + (1 << (n - i))
        return a
