class Solution {
    public static int overlapInt(int[][] arr) {
        int mx = 0;
        for (int[] a : arr) mx = Math.max(mx, a[1]);
        int[] diff = new int[mx + 2];
        for (int[] a : arr) { diff[a[0]]++; diff[a[1] + 1]--; }
        int res = 0, cur = 0;
        for (int x : diff) res = Math.max(res, cur += x);
        return res;
    }
}
