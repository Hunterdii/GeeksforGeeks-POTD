
class Solution {
    public int missingNumber(int[] a) {
        int n = a.length;
        for (int i = 0; i < n; i++) if (a[i] <= 0) a[i] = n + 1;
        for (int i = 0; i < n; i++) {
            int x = Math.abs(a[i]);
            if (x <= n) a[x - 1] = -Math.abs(a[x - 1]);
        }
        for (int i = 0; i < n; i++) if (a[i] > 0) return i + 1;
        return n + 1;
    }
}
