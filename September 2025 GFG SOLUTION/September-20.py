class Solution:
    def longestSubarray(self, a):
        n, res = len(a), 0
        l, r, s = [-1] * n, [n] * n, []
        for i in range(n - 1, -1, -1):
            while s and a[s[-1]] <= a[i]: s.pop()
            if s: r[i] = s[-1]
            s.append(i)
        s.clear()
        for i in range(n):
            while s and a[s[-1]] <= a[i]: s.pop()
            if s: l[i] = s[-1]
            s.append(i)
            length = r[i] - l[i] - 1
            if length >= a[i]: res = max(res, length)
        return res
