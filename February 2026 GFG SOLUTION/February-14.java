class Solution {
    public int minTime(int[] arr, int k) {
        int l = 0, r = 0;
        for (int x : arr) {
            l = Math.max(l, x);
            r += x;
        }
        while (l < r) {
            int m = l + (r - l) / 2, cnt = 1, sum = 0;
            boolean ok = true;
            for (int x : arr) {
                if (x > m) { ok = false; break; }
                if (sum + x > m) { cnt++; sum = x; }
                else sum += x;
            }
            if (ok && cnt <= k) r = m;
            else l = m + 1;
        }
        return l;
    }
}
