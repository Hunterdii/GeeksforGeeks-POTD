class Solution:
    def safeNodes(self, V, edges):
        out, g = [0] * V, [[] for _ in range(V)]
        for u, v in edges: out[u] += 1; g[v].append(u)
        q, safe = [], [0] * V
        for i in range(V):
            if not out[i]: q.append(i); safe[i] = 1
        for u in q:
            for v in g[u]:
                if not safe[v]:
                    out[v] -= 1
                    if not out[v]: q.append(v); safe[v] = 1
        return [i for i in range(V) if safe[i]]
