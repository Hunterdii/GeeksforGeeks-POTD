class Solution:
    def maxWater(self, arr):
        l, r, lmax, rmax, res = 0, len(arr) - 1, 0, 0, 0
        while l < r:
            if arr[l] < arr[r]:
                lmax = max(lmax, arr[l])
                res += lmax - arr[l]
                l += 1
            else:
                rmax = max(rmax, arr[r])
                res += rmax - arr[r]
                r -= 1
        return res
