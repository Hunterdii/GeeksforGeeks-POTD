class Solution:
    def minConnect(self, V, edges):
        comp, e = V, len(edges)
        if e < V - 1: return -1
        p = list(range(V))
        def find(x): 
            if p[x] != x: p[x] = find(p[x])
            return p[x]
        for u, v in edges:
            x, y = find(u), find(v)
            if x != y: p[x] = y; comp -= 1
        return comp - 1
