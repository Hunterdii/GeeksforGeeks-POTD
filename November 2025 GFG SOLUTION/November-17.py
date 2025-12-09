class Solution:
    def maxSumIS(self, arr):
        n = len(arr)
        dp = arr[:]  
        for i in range(n):
            for j in range(i):
                if arr[j] < arr[i]:
                    dp[i] = max(dp[i], dp[j] + arr[i])
        return max(dp)
