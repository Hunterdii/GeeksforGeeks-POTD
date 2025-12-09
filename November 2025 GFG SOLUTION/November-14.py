class Solution:
    def mergeStones(self, stones, k):
        n = len(stones)
        if (n - 1) % (k - 1): return -1
        s = [0] * (n + 1)
        for i in range(n): s[i + 1] = s[i] + stones[i]
        dp = [[0] * n for _ in range(n)]
        for l in range(k, n + 1):
            for i in range(n - l + 1):
                j = i + l - 1
                dp[i][j] = float('inf')
                for m in range(i, j, k - 1):
                    dp[i][j] = min(dp[i][j], dp[i][m] + dp[m + 1][j])
                if (j - i) % (k - 1) == 0:
                    dp[i][j] += s[j + 1] - s[i]
        return dp[0][n - 1]
