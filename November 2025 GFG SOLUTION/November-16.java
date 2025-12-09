class Solution {
    public int LCIS(int[] a, int[] b) {
        int m = a.length, n = b.length, res = 0;
        int[] dp = new int[n];

        for (int i = 0; i < m; i++) {
            int cur = 0;
            for (int j = 0; j < n; j++) {
                if (a[i] == b[j]) {
                    dp[j] = Math.max(dp[j], cur + 1);
                }
                if (b[j] < a[i]) {
                    cur = Math.max(cur, dp[j]);
                }
                res = Math.max(res, dp[j]);
            }
        }
        return res;
    }
}
