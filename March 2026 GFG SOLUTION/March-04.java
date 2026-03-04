class Solution {
    public int maxSubarrayXOR(int[] arr, int k) {
        int xr = 0, res = 0;
        for (int i = 0; i < arr.length; i++) {
            xr ^= arr[i];
            if (i >= k) xr ^= arr[i - k];
            if (i >= k - 1) res = Math.max(res, xr);
        }
        return res;
    }
}
