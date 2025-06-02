class Solution:
    def uniquePaths(self, grid):
        r, c = len(grid), len(grid[0])
        dp = [0] * c
        dp[0] = 1 if grid[0][0] == 0 else 0
        for i in range(r):
            for j in range(c):
                if grid[i][j] == 1:
                    dp[j] = 0
                elif j > 0:
                    dp[j] += dp[j - 1]
        return dp[-1]
