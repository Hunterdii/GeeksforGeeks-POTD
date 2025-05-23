class Solution {
    static int noOfWays(int m, int n, int x) {
        int mod = (int)1e9 + 7;
        int[][] dp = new int[n + 1][x + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= x; ++j)
                for (int k = 1; k <= m && k <= j; ++k)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod;
        return dp[n][x];
    }
}
