class Solution {
    public int minSquares(int n) {
        int s = (int)Math.sqrt(n);
        if(s * s == n) return 1;
        for(int i = 1; i * i <= n; i++) {
            int r = (int)Math.sqrt(n - i * i);
            if(r * r == n - i * i) return 2;
        }
        while(n % 4 == 0) n /= 4;
        return n % 8 == 7 ? 4 : 3;
    }
}
