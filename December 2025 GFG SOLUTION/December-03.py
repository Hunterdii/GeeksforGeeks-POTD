class Solution:
    def tsp(self, cost):
        n = len(cost)
        if n <= 1: return cost[0][0] if n else 0
        FULL = (1 << n) - 1
        dp = [[float('inf')] * n for _ in range(1 << n)]
        dp[1][0] = 0
        for mask in range(1, (1 << n)):
            for i in range(n):
                if not (mask & (1 << i)) or dp[mask][i] == float('inf'): continue
                for j in range(n):
                    if mask & (1 << j): continue
                    nxt = mask | (1 << j)
                    dp[nxt][j] = min(dp[nxt][j], dp[mask][i] + cost[i][j])
        ans = float('inf')
        for i in range(n):
            if dp[FULL][i] != float('inf'):
                ans = min(ans, dp[FULL][i] + cost[i][0])
        return ans
