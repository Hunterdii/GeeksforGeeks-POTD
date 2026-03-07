class Solution:
    def noOfWays(self, m, n, x):
        dp = [0] * (x + 1)
        dp[0] = 1
        for i in range(1, n + 1):
            for j in range(x, 0, -1):
                dp[j] = 0
                for k in range(1, min(m, j) + 1):
                    dp[j] += dp[j - k]
            dp[0] = 0
        return dp[x]
