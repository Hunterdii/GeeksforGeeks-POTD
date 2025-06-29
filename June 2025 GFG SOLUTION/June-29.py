class Solution:
    def splitArray(self, a, k):
        l, r = max(a), sum(a)
        while l < r:
            m, s, c = (l + r) // 2, 0, 1
            for x in a:
                if s + x > m:
                    c += 1
                    s = 0
                s += x
            if c <= k:
                r = m
            else:
                l = m + 1
        return l
