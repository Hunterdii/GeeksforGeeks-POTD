from collections import Counter
class Solution:
    def validgroup(self, arr, k):
        m = Counter(arr)
        for v in sorted(m.keys()):
            f = m[v]
            if f == 0: continue
            for i in range(1, k):
                if m[v + i] < f: return False
                m[v + i] -= f
        return True
