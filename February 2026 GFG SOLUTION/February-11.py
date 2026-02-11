class Solution:
    def minCost(self, heights, cost):
        n = len(heights)
        v = sorted(zip(heights, cost))
        total = sum(cost)
        s, res = 0, 0
        for h, c in v:
            s += c
            if s >= (total + 1) // 2:
                for i in range(n):
                    res += abs(heights[i] - h) * cost[i]
                return res
        return 0
