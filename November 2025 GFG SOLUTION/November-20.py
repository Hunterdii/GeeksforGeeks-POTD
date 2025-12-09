class Solution:
    def minCost(self, s, t, transform, cost):
        INF = int(1e9)
        d = [[INF] * 26 for _ in range(26)]
        for i in range(26): d[i][i] = 0
        for i in range(len(transform)):
            u, v = ord(transform[i][0]) - ord('a'), ord(transform[i][1]) - ord('a')
            d[u][v] = min(d[u][v], cost[i])
        for k in range(26):
            for i in range(26):
                for j in range(26):
                    if d[i][k] < INF and d[k][j] < INF:
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j])
        res = 0
        for i in range(len(s)):
            if s[i] == t[i]: continue
            mn, a, b = INF, ord(s[i]) - ord('a'), ord(t[i]) - ord('a')
            for c in range(26):
                if d[a][c] < INF and d[b][c] < INF:
                    mn = min(mn, d[a][c] + d[b][c])
            if mn == INF: return -1
            res += mn
        return res
