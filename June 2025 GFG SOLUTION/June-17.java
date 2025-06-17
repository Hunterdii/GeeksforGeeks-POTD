class Solution {
    public int minimumCoins(int[] a, int k) {
        Arrays.sort(a);
        int n = a.length, t = Arrays.stream(a).sum(), res = t, w = 0, p = 0, e = 0;
        for (int s = 0; s < n; s++) {
            while (e < n && a[e] - a[s] <= k) w += a[e++];
            int r = Math.max(0, (t - p - w) - (n - e) * (a[s] + k));
            res = Math.min(res, p + r);
            if (e == s) e++; else w -= a[s];
            p += a[s];
        }
        return res;
    }
}
