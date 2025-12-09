class Solution {
    public int minCost(int keys[], int freq[]) {
        int n = keys.length;
        int[][] dp = new int[n][n];
        int[] ps = new int[n + 1];
        for (int i = 0; i < n; i++) ps[i + 1] = ps[i] + freq[i];
        for (int i = 0; i < n; i++) dp[i][i] = freq[i];
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                dp[i][j] = Integer.MAX_VALUE;
                int fsum = ps[j + 1] - ps[i];
                for (int r = i; r <= j; r++) {
                    int c = (r > i ? dp[i][r - 1] : 0) + (r < j ? dp[r + 1][j] : 0) + fsum;
                    dp[i][j] = Math.min(dp[i][j], c);
                }
            }
        }
        return dp[0][n - 1];
    }
}
