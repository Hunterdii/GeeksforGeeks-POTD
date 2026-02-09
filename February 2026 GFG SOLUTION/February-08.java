class Solution {
    int maxProduct(int[] arr) {
        int mx = arr[0], mn = arr[0], r = arr[0];
        for (int i = 1; i < arr.length; i++) {
            int a = mx * arr[i], b = mn * arr[i];
            mx = Math.max(Math.max(a, b), arr[i]);
            mn = Math.min(Math.min(a, b), arr[i]);
            r = Math.max(r, mx);
        }
        return r;
    }
}
