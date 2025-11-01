class Solution:
    def findOrder(self, n, prerequisites):
        g = [[] for _ in range(n)]
        d = [0] * n
        for a, b in prerequisites:
            g[b].append(a)
            d[a] += 1
        q = [i for i in range(n) if d[i] == 0]
        r = []
        while q:
            u = q.pop(0)
            r.append(u)
            for v in g[u]:
                d[v] -= 1
                if d[v] == 0: q.append(v)
        return r if len(r) == n else []
