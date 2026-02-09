class Solution:
    def maxProduct(self, arr):
        mx = mn = r = arr[0]
        for i in range(1, len(arr)):
            a, b = mx * arr[i], mn * arr[i]
            mx = max(a, b, arr[i])
            mn = min(a, b, arr[i])
            r = max(r, mx)
        return r
