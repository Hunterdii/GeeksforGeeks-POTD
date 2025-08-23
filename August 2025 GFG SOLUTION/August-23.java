class Solution {
    public int findPages(int[] arr, int k) {
        if (k > arr.length) return -1;
        int l = arr[0], r = 0;
        for (int x : arr) {
            l = Math.max(l, x);
            r += x;
        }
        while (l < r) {
            int m = l + (r - l) / 2;
            int s = 1, p = 0;
            for (int x : arr) {
                if (p + x > m) { s++; p = x; }
                else p += x;
            }
            if (s <= k) r = m;
            else l = m + 1;
        }
        return l;
    }
}
