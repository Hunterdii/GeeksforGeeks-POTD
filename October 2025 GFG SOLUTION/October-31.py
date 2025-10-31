class Solution:
    def shortCycle(self, V, edges):
        from collections import deque
        adj = [[] for _ in range(V)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        res = float('inf')
        for i in range(V):
            d = [-1] * V
            p = [-1] * V
            q = deque([i])
            d[i] = 0
            while q:
                u = q.popleft()
                for v in adj[u]:
                    if d[v] == -1:
                        d[v] = d[u] + 1
                        p[v] = u
                        q.append(v)
                    elif p[u] != v:
                        res = min(res, d[u] + d[v] + 1)
        return -1 if res == float('inf') else res
