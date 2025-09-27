class Solution {
    public int kBitFlips(int[] a, int k) {
        int n = a.length, flips = 0, flip = 0;
        for (int i = 0; i < n; i++) {
            if (i >= k && a[i - k] > 1) flip ^= 1;
            if ((a[i] ^ flip) == 0) {
                if (i + k > n) return -1;
                a[i] = 2;
                flip ^= 1;
                flips++;
            }
        }
        return flips;
    }
}
