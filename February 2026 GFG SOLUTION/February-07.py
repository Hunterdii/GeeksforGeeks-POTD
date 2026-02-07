class Solution:
    def maxSum(self, arr):
        n = len(arr)
        s = sum(arr)
        cur = sum(i * arr[i] for i in range(n))
        mx = cur
        for i in range(n - 1):
            cur += n * arr[i] - s
            mx = max(mx, cur)
        return mx
