class Solution:
    class Node:
        def __init__(self):
            self.ch = [None, None]
            self.cnt = 0
    def add(self, r, v):
        for i in range(31, -1, -1):
            b = (v >> i) & 1
            if not r.ch[b]: r.ch[b] = self.Node()
            r.ch[b].cnt += 1
            r = r.ch[b]
    def query(self, r, v, k):
        res = 0
        for i in range(31, -1, -1):
            if not r: break
            bv, bk = (v >> i) & 1, (k >> i) & 1
            if bk:
                if r.ch[bv]: res += r.ch[bv].cnt
                r = r.ch[1 - bv]
            else: r = r.ch[bv]
        return res
    def cntPairs(self, a, k):
        r = self.Node()
        ans = 0
        for x in a:
            ans += self.query(r, x, k)
            self.add(r, x)
        return ans
