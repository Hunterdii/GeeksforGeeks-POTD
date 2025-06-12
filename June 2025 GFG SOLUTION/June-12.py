class Solution:
    def printKClosest(self, a, k, x):
        n, l, h, p = len(a), 0, len(a) - 1, -1
        while l <= h:
            m = (l + h) // 2
            if a[m] < x: p = m; l = m + 1
            else: h = m - 1
        i, j, r = p, p + 1, []
        if j < n and a[j] == x: j += 1
        while i >= 0 and j < n and len(r) < k:
            r.append(a[i] if abs(a[i] - x) < abs(a[j] - x) else a[j])
            if abs(a[i] - x) < abs(a[j] - x): i -= 1
            else: j += 1
        while i >= 0 and len(r) < k: r.append(a[i]); i -= 1
        while j < n and len(r) < k: r.append(a[j]); j += 1
        return r
