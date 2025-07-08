from collections import Counter
class Solution:
    def findGreater(self, a):
        f = Counter(a)
        r, s = [-1]*len(a), []
        for i, v in enumerate(a):
            while s and f[v] > f[a[s[-1]]]:
                r[s.pop()] = v
            s.append(i)
        return r
