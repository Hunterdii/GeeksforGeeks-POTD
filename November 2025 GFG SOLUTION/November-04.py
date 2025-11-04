class Solution:
    def minCost(self, height):
        n = len(height)
        if n == 1: return 0
        a, b = 0, abs(height[1] - height[0])
        for i in range(2, n):
            c = min(b + abs(height[i] - height[i - 1]), a + abs(height[i] - height[i - 2]))
            a, b = b, c
        return b
