class Solution {
    public int tsp(int[][] cost) {
        int n = cost.length;
        if (n <= 1) return n == 1 ? cost[0][0] : 0;
        int FULL = (1 << n) - 1;
        int[][] dp = new int[1 << n][n];
        for (int[] row : dp) Arrays.fill(row, Integer.MAX_VALUE);
        dp[1][0] = 0;
        for (int mask = 1; mask <= FULL; mask++) {
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) == 0 || dp[mask][i] == Integer.MAX_VALUE) continue;
                for (int j = 0; j < n; j++) {
                    if ((mask & (1 << j)) != 0) continue;
                    int nxt = mask | (1 << j);
                    dp[nxt][j] = Math.min(dp[nxt][j], dp[mask][i] + cost[i][j]);
                }
            }
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++)
            if (dp[FULL][i] != Integer.MAX_VALUE)
                ans = Math.min(ans, dp[FULL][i] + cost[i][0]);
        return ans;
    }
}
