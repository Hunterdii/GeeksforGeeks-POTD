class Solution:
    def LCIS(self, a, b):
        m, n = len(a), len(b)
        dp = [0] * n
        res = 0

        for i in range(m):
            cur = 0
            for j in range(n):
                if a[i] == b[j]:
                    dp[j] = max(dp[j], cur + 1)
                if b[j] < a[i]:
                    cur = max(cur, dp[j])
                res = max(res, dp[j])

        return res
