class Solution:
    def wildCard(self, txt, pat):
        n, m = len(txt), len(pat)
        dp = [[False] * (m + 1) for _ in range(n + 1)]

        # Empty pattern matches empty text
        dp[0][0] = True

        # Handle patterns starting with '*'
        for j in range(1, m + 1):
            if pat[j - 1] == '*':
                dp[0][j] = dp[0][j - 1]

        # Fill DP table
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if pat[j - 1] == txt[i - 1] or pat[j - 1] == '?':
                    dp[i][j] = dp[i - 1][j - 1]
                elif pat[j - 1] == '*':
                    dp[i][j] = dp[i - 1][j] or dp[i][j - 1]
                else:
                    dp[i][j] = False

        dp[0][0] = True
        for j in range(1, m + 1):
            if pat[j - 1] == '*': dp[0][j] = dp[0][j - 1]
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if pat[j - 1] == '*':
                    dp[i][j] = dp[i][j - 1] or dp[i - 1][j]
                elif pat[j - 1] == '?' or txt[i - 1] == pat[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
        return dp[n][m]
