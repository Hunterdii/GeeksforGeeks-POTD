class Solution:
    def countPaths(self, E, V, S, D):
        from collections import defaultdict, deque
        G = defaultdict(list); I = [0] * V
        for u, v in E: G[u].append(v); I[v] += 1
        Q = deque(i for i in range(V) if I[i] == 0)
        T, dp = [], [0] * V; dp[D] = 1
        while Q:
            u = Q.popleft(); T.append(u)
            for v in G[u]:
                I[v] -= 1
                if I[v] == 0: Q.append(v)
        for u in reversed(T):
            for v in G[u]: dp[u] += dp[v]
        return dp[S]
