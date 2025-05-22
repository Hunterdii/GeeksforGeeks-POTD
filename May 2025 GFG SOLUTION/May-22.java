class Solution {
    static int minDeletions(String s) {
        int n = s.length();
        int[] dp = new int[n], prev = new int[n];
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = 1;
            for (int j = i + 1; j < n; ++j)
                dp[j] = s.charAt(i) == s.charAt(j) ? prev[j - 1] + 2 : Math.max(prev[j], dp[j - 1]);
            prev = dp.clone();
        }
        return n - dp[n - 1];
    }
}
