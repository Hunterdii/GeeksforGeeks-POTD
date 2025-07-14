class Solution {
    public int cuts(String s) {
        if (s.charAt(0) == '0') return -1;
        int n = s.length();
        Set<Long> powers = new HashSet<>();
        for (long p = 1; p <= 1000000000L; p *= 5) powers.add(p);
        int[] dp = new int[n + 1];
        Arrays.fill(dp, n + 1);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s.charAt(i) == '0') continue;
            long num = 0;
            for (int j = i; j < n && num <= 1000000000L; ++j) {
                num = (num << 1) + (s.charAt(j) - '0');
                if (powers.contains(num) && dp[j + 1] <= n)
                    dp[i] = Math.min(dp[i], 1 + dp[j + 1]);
            }
        }
        return dp[0] > n ? -1 : dp[0];
    }
}
