class Solution:
    def minCost(self, heights, cost):
        l, h = 0, max(heights)
        while l < h:
            m = l + (h - l) // 2
            c1 = sum(abs(heights[i] - m) * cost[i] for i in range(len(heights)))
            c2 = sum(abs(heights[i] - m - 1) * cost[i] for i in range(len(heights)))
            if c1 <= c2:
                h = m
            else:
                l = m + 1
        return sum(abs(heights[i] - l) * cost[i] for i in range(len(heights)))
