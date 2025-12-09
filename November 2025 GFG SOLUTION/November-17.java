class Solution {
    public int maxSumIS(int[] arr) {
        int n = arr.length;
        int res = 0;
        int[] dp = new int[n];
        for (int i = 0; i < n; i++) {
            dp[i] = arr[i];
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i])
                    dp[i] = Math.max(dp[i], dp[j] + arr[i]);
            }
            res = Math.max(res, dp[i]);
        }
        return res;
    }
}
