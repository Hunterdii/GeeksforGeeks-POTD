class Solution:
    def countSubset(self, arr, k):
        n, m = len(arr), len(arr) // 2
        lf, rf = {}, {}
        def gen(i, e, s, f):
            if i == e: f[s] = f.get(s, 0) + 1; return
            gen(i + 1, e, s + arr[i], f)
            gen(i + 1, e, s, f)
        gen(0, m, 0, lf)
        gen(m, n, 0, rf)
        return sum(c * rf.get(k - s, 0) for s, c in lf.items())
