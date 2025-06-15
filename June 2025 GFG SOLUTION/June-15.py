class Solution:
    def smallestDivisor(self, arr, k):
        l, h = 1, max(arr)
        while l < h:
            m, s = l + (h - l) // 2, 0
            for x in arr:
                s += (x + m - 1) // m
            if s <= k:
                h = m
            else:
                l = m + 1
        return l
