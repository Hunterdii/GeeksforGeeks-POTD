class Solution:
    def minCost(self, keys, freq):
        n = len(keys)
        dp = [[0] * n for _ in range(n)]
        ps = [0] * (n + 1)
        for i in range(n):
            ps[i + 1] = ps[i] + freq[i]
            dp[i][i] = freq[i]
        for l in range(2, n + 1):
            for i in range(n - l + 1):
                j = i + l - 1
                dp[i][j] = float('inf')
                fsum = ps[j + 1] - ps[i]
                for r in range(i, j + 1):
                    c = (dp[i][r - 1] if r > i else 0) + (dp[r + 1][j] if r < j else 0) + fsum
                    dp[i][j] = min(dp[i][j], c)
        return dp[0][n - 1]
