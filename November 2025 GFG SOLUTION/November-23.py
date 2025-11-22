class Solution:
    def maxRemove(self, stones):
        p = {}
        def find(x):
            if x not in p: p[x] = x
            if p[x] != x: p[x] = find(p[x])
            return p[x]
        def union(x, y):
            p[find(x)] = find(y)
        for r, c in stones:
            union(r, ~c)
        return len(stones) - len({find(r) for r, c in stones})
