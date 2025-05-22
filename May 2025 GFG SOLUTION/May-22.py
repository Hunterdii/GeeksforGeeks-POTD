class Solution:
    def minDeletions(self, s):
        n = len(s)
        dp = [0] * n
        prev = [0] * n
        for i in range(n - 1, -1, -1):
            dp[i] = 1
            for j in range(i + 1, n):
                dp[j] = prev[j - 1] + 2 if s[i] == s[j] else max(prev[j], dp[j - 1])
            prev = dp[:]
        return n - dp[-1]
