class Solution {
    static int noOfWays(int m, int n, int x) {
        int[] dp = new int[x + 1];
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = x; j >= 1; j--) {
                dp[j] = 0;
                for (int k = 1; k <= m && k <= j; k++)
                    dp[j] += dp[j - k];
            }
            dp[0] = 0;
        }
        return dp[x];
    }
}
