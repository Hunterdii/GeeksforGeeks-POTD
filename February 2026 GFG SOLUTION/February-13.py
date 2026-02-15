class Solution:
    def getCount(self, n, d):
        lo, hi = 1, n
        while lo <= hi:
            mid = (lo + hi) // 2
            digit_sum = sum(int(digit) for digit in str(mid))
            if mid - digit_sum >= d:
                hi = mid - 1
            else:
                lo = mid + 1
        return n - hi
