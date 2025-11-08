class Solution {
    public int maxProfit(int[][] jobs) {
        Arrays.sort(jobs, (a, b) -> a[0] - b[0]);
        int n = jobs.length;
        int[] dp = new int[n + 1];
        for (int i = n - 1; i >= 0; i--) {
            int l = i + 1, r = n - 1, nxt = n;
            while (l <= r) {
                int m = (l + r) / 2;
                if (jobs[m][0] >= jobs[i][1]) {
                    nxt = m;
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            dp[i] = Math.max(jobs[i][2] + dp[nxt], dp[i + 1]);
        }
        return dp[0];
    }
}
