class Solution {
    boolean check(int[] a, int k, int w, int h) {
        int n = a.length;
        int[] add = new int[n];
        for (int i = 0; i < n; i++) {
            int cur = a[i] + (i > 0 ? add[i - 1] : 0);
            if (i >= w) cur -= add[i - w];
            if (cur < h) {
                int need = h - cur;
                if (need > k) return false;
                k -= need;
                add[i] = (i > 0 ? add[i - 1] : 0) + need;
            } else {
                add[i] = i > 0 ? add[i - 1] : 0;
            }
        }
        return true;
    }
    
    public int maxMinHeight(int[] a, int k, int w) {
        int lo = a[0];
        for (int x : a) lo = Math.min(lo, x);
        int hi = lo + k, ans = lo;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(a, k, w, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
}
