class Solution:
    def kokoEat(self, arr, k):
        lo, hi = 1, max(arr)
        while lo < hi:
            mid = (lo + hi) // 2
            hours = sum((pile + mid - 1) // mid for pile in arr)
            if hours <= k:
                hi = mid
            else:
                lo = mid + 1
        return lo
