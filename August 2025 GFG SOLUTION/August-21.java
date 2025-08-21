class Solution {
    public int maxMinDiff(int[] a, int k) {
        Arrays.sort(a);
        int l = 0, r = a[a.length - 1] - a[0], ans = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int cnt = 1, last = a[0];
            for (int i = 1; i < a.length && cnt < k; i++)
                if (a[i] - last >= m) { cnt++; last = a[i]; }
            if (cnt >= k) { ans = m; l = m + 1; } else r = m - 1;
        }
        return ans;
    }
}
