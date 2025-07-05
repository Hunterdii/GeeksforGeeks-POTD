class Solution:
    def maxSum(self, arr):
        ans = 0
        for i in range(1, len(arr)):
            ans = max(arr[i] + arr[i - 1], ans)
        return ans
