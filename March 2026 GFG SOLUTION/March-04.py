class Solution:
    def maxSubarrayXOR(self, arr, k):
        xr = res = 0
        for i in range(len(arr)):
            xr ^= arr[i]
            if i >= k:
                xr ^= arr[i - k]
            if i >= k - 1:
                res = max(res, xr)
        return res
