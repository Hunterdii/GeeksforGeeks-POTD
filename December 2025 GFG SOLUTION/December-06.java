class Solution {
    public int maximumAmount(int arr[]) {
        int n = arr.length, s = 0;
        int[] dp = new int[n];
        for (int i = n - 1; i >= 0; i--) {
            s += arr[i];
            for (int j = i; j < n; j++)
                dp[j] = (i == j) ? arr[j] : Math.max(arr[i] - dp[j], arr[j] - dp[j - 1]);
        }
        return (s + dp[n - 1]) / 2;
    }
}
