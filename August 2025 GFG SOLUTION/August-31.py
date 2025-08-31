class Solution:
    def maxWater(self, h):
        l, r, ans = 0, len(h) - 1, 0
        while l < r:
            ans = max(ans, min(h[l], h[r]) * (r - l))
            l, r = (l + 1, r) if h[l] < h[r] else (l, r - 1)
        return ans
