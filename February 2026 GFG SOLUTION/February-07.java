class Solution {
    int maxSum(int[] arr) {
        int n = arr.length, s = 0, cur = 0, mx;
        for (int i = 0; i < n; i++) { s += arr[i]; cur += i * arr[i]; }
        mx = cur;
        for (int i = 0; i < n - 1; i++) {
            cur += n * arr[i] - s;
            mx = Math.max(mx, cur);
        }
        return mx;
    }
}
