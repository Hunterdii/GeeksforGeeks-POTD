class Solution {
    public int median(int[][] mat) {
        int n = mat.length, m = mat[0].length;
        int lo = mat[0][0], hi = mat[0][m-1];
        for (int i = 1; i < n; i++) {
            lo = Math.min(lo, mat[i][0]);
            hi = Math.max(hi, mat[i][m-1]);
        }
        int req = (n * m + 1) / 2;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2, cnt = 0;
            for (int i = 0; i < n; i++) {
                int left = 0, right = m;
                while (left < right) {
                    int center = left + (right - left) / 2;
                    if (mat[i][center] <= mid) left = center + 1;
                    else right = center;
                }
                cnt += left;
            }
            if (cnt < req) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
}
