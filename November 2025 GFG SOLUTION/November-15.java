class Solution {
    public int minCutCost(int n, int[] cuts) {
        int m = cuts.length + 2;
        int[] c = new int[m];
        c[0] = 0;
        c[m - 1] = n;
        System.arraycopy(cuts, 0, c, 1, cuts.length);
        Arrays.sort(c);
        int[][] dp = new int[m][m];
        for (int gap = 2; gap < m; gap++) {
            for (int i = 0; i + gap < m; i++) {
                int j = i + gap;
                dp[i][j] = Integer.MAX_VALUE;
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k][j] + c[j] - c[i]);
                }
            }
        }
        return dp[0][m - 1];
    }
}
