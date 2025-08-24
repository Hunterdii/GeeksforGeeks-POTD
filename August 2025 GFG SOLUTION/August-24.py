class Solution:
    def minDaysBloom(self, arr, k, m):
        if k * m > len(arr): return -1
        l, r = min(arr), max(arr)
        while l < r:
            mid = (l + r) // 2
            flowers = bouquets = 0
            for bloom in arr:
                if bloom <= mid:
                    flowers += 1
                    if flowers == k:
                        bouquets += 1
                        flowers = 0
                else:
                    flowers = 0
            if bouquets >= m:
                r = mid
            else:
                l = mid + 1
        return l
