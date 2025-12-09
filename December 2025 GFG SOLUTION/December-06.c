int maximumAmount(int* arr, int n) {
    int s = 0, *dp = (int*)malloc(n * sizeof(int));
    for (int i = n - 1; i >= 0; i--) {
        s += arr[i];
        for (int j = i; j < n; j++)
            dp[j] = (i == j) ? arr[j] : (arr[i] - dp[j] > arr[j] - dp[j - 1] ? arr[i] - dp[j] : arr[j] - dp[j - 1]);
    }
    int res = (s + dp[n - 1]) / 2;
    free(dp);
    return res;
}
