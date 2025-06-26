class Solution {
    public int minValue(String s, int k) {
        int[] f = new int[26]; int m = 0;
        for (char c : s.toCharArray()) m = Math.max(m, ++f[c - 'a']);
        int[] b = new int[m + 1];
        for (int x : f) if (x > 0) b[x]++;
        while (k > 0 && m > 0) {
            if (b[m] <= k) {
                k -= b[m]; 
                b[m - 1] += b[m]; 
                b[m--] = 0;
            } else {
                b[m] -= k; 
                b[m - 1] += k; 
                k = 0;
            }
        }
        int r = 0;
        for (int i = 1; i <= m; i++) r += i * i * b[i];
        return r;
    }
}
