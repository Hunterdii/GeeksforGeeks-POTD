class Solution:
    def getMinDiff(self, a, k):
        a.sort()
        n = len(a)
        ans = a[n-1] - a[0]
        for i in range(1, n):
            if a[i] >= k:
                mn = min(a[0] + k, a[i] - k)
                mx = max(a[n-1] - k, a[i-1] + k)
                ans = min(ans, mx - mn)
        return ans
