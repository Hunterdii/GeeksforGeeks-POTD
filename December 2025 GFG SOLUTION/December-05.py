class Solution:
    def minCost(self, costs):
        n, m = len(costs), len(costs[0])
        if m == 1 and n > 1: return -1
        m1, m2, idx = 0, 0, -1
        for i in range(n):
            nm1, nm2, nidx = float('inf'), float('inf'), -1
            for j in range(m):
                c = costs[i][j] + (m2 if j == idx else m1)
                if c < nm1: nm2, nm1, nidx = nm1, c, j
                elif c < nm2: nm2 = c
            m1, m2, idx = nm1, nm2, nidx
        return m1
