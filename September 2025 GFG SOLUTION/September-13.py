class Solution:
    def minCost(self, n, m, x, y):
        x.sort(reverse=True); y.sort(reverse=True)
        h = v = i = j = cost = 0; h = v = 1
        while i < len(x) and j < len(y):
            if x[i] > y[j]: cost += x[i] * h; v += 1; i += 1
            else: cost += y[j] * v; h += 1; j += 1
        while i < len(x): cost += x[i] * h; i += 1
        while j < len(y): cost += y[j] * v; j += 1
        return cost
