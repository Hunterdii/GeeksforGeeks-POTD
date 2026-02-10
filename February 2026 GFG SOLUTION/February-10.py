class Solution:
    def kokoEat(self, arr, k):
        l, r = 1, max(arr)
        ans = r
        while l <= r:
            m = (l + r) // 2
            h = sum((x + m - 1) // m for x in arr)
            if h <= k:
                ans = m
                r = m - 1
            else:
                l = m + 1
        return ans
