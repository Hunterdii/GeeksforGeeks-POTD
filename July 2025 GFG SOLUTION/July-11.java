class Solution {
    public int countConsec(int n) {
        int a = 0, b = 0;
        for (int i = n; i > 0; i--) {
            int tmp = a + b;
            b = a + (1 << (n - i));
            a = tmp;
        }
        return a;
    }
}
