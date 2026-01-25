class Solution {
    int findWays(int n) {
        if ((n & 1) == 1) return 0;
        n >>= 1;
        long res = 1;
        for (int i = 0; i < n; i++) {
            res = res * (2 * n - i) / (i + 1);
        }
        return (int)(res / (n + 1));
    }
}
