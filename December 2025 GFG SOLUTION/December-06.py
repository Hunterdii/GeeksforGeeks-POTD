class Solution:
    def maximumAmount(self, arr):
        n, s = len(arr), 0
        dp = [0] * n
        for i in range(n - 1, -1, -1):
            s += arr[i]
            for j in range(i, n):
                dp[j] = arr[j] if i == j else max(arr[i] - dp[j], arr[j] - dp[j - 1])
        return (s + dp[n - 1]) // 2
