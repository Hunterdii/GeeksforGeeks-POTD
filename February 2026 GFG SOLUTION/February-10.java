class Solution {
    public int kokoEat(int[] arr, int k) {
        int l = 1, r = 0, ans = 0;
        for (int x : arr) r = Math.max(r, x);
        ans = r;
        while (l <= r) {
            int m = l + (r - l) / 2, h = 0;
            for (int x : arr) h += (x + m - 1) / m;
            if (h <= k) { ans = m; r = m - 1; }
            else l = m + 1;
        }
        return ans;
    }
}
