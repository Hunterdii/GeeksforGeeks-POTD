class Solution {
    public int splitArray(int[] a, int k) {
        int l = 0, r = 0;
        for (int x : a) {
            l = Math.max(l, x);
            r += x;
        }
        while (l < r) {
            int m = (l + r) / 2, s = 0, c = 1;
            for (int x : a) {
                if (s + x > m) {
                    c++;
                    s = 0;
                }
                s += x;
            }
            if (c <= k) r = m;
            else l = m + 1;
        }
        return l;
    }
}
