class Solution:
    def subarrayRanges(self, a):
        n = len(a)
        res = 0
        s = []
        for i in range(n + 1):
            while s and (i == n or a[s[-1]] > a[i]):
                j = s.pop()
                k = s[-1] if s else -1
                res -= a[j] * (i - j) * (j - k)
            s.append(i)
        s.clear()
        for i in range(n + 1):
            while s and (i == n or a[s[-1]] < a[i]):
                j = s.pop()
                k = s[-1] if s else -1
                res += a[j] * (i - j) * (j - k)
            s.append(i)
        return res
