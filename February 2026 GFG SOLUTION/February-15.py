class Solution:
    def findMinDiff(self, a, m):
        a.sort()
        return min(a[i + m - 1] - a[i] for i in range(len(a) - m + 1))
