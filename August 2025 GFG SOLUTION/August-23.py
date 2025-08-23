class Solution:
    def findPages(self, arr, k):
        if k > len(arr): return -1
        l, r = max(arr), sum(arr)
        while l < r:
            m = (l + r) // 2
            s, p = 1, 0
            for x in arr:
                if p + x > m: s, p = s + 1, x
                else: p += x
            r, l = (m, l) if s <= k else (r, m + 1)
        return l
