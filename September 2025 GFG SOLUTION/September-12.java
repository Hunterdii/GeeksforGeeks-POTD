class Solution {
    public int getMinDiff(int[] a, int k) {
        Arrays.sort(a);
        int n = a.length, ans = a[n-1] - a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] >= k) {
                int mn = Math.min(a[0] + k, a[i] - k);
                int mx = Math.max(a[n-1] - k, a[i-1] + k);
                ans = Math.min(ans, mx - mn);
            }
        }
        return ans;
    }
}
