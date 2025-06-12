class Solution {
    int[] printKClosest(int[] a, int k, int x) {
        int n = a.length, l = 0, h = n - 1, p = -1;
        while (l <= h) {
            int m = (l + h) / 2;
            if (a[m] < x) { p = m; l = m + 1; }
            else h = m - 1;
        }
        int i = p, j = p + 1;
        if (j < n && a[j] == x) j++;
        int[] r = new int[k]; int idx = 0;
        while (i >= 0 && j < n && idx < k)
            r[idx++] = Math.abs(a[i] - x) < Math.abs(a[j] - x) ? a[i--] : a[j++];
        while (i >= 0 && idx < k) r[idx++] = a[i--];
        while (j < n && idx < k) r[idx++] = a[j++];
        return r;
    }
}
