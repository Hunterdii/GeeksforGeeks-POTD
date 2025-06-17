class Solution:
    def minimumCoins(self, a, k):
        a.sort()
        n, t, res, w, p, e = len(a), sum(a), sum(a), 0, 0, 0
        for s in range(n):
            while e < n and a[e] - a[s] <= k:
                w += a[e]
                e += 1
            r = max(0, (t - p - w) - (n - e) * (a[s] + k))
            res = min(res, p + r)
            if e == s: e += 1
            else: w -= a[s]
            p += a[s]
        return res
