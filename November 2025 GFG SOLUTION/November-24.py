class Solution:
    def secondMST(self, V, edges):
        edges.sort(key=lambda x: x[2])
        p = list(range(V))
        r = [0] * V
        def find(x):
            if p[x] != x: p[x] = find(p[x])
            return p[x]
        def unite(a, b):
            a, b = find(a), find(b)
            if a == b: return False
            if r[a] < r[b]: a, b = b, a
            p[b] = a
            if r[a] == r[b]: r[a] += 1
            return True
        mst, tree = 0, []
        for u, v, w in edges:
            if unite(u, v):
                mst += w
                tree.append((u, v, w))
        ans = float('inf')
        for su, sv, sw in tree:
            p = list(range(V))
            r = [0] * V
            cost = cnt = 0
            for u, v, w in edges:
                if (u == su and v == sv) or (u == sv and v == su): continue
                if unite(u, v):
                    cost += w
                    cnt += 1
                    if cnt == V - 1: break
            if cnt == V - 1 and cost > mst: ans = min(ans, cost)
        return -1 if ans == float('inf') else ans
