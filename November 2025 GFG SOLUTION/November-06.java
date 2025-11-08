class Solution {
    public int numberOfWays(int n) {
        if (n <= 1) return 1;
        int a = 1, b = 1;
        while (n-- > 1) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
}
