class Solution {
    public static int countNumbers(int n) {
        int c = 0, lim = (int)Math.sqrt(n);
        int[] spf = new int[lim + 1];
        for (int i = 2; i <= lim; i++) spf[i] = i;
        for (int i = 2; i * i <= lim; i++)
            if (spf[i] == i)
                for (int j = i * i; j <= lim; j += i)
                    if (spf[j] == j) spf[j] = i;
        for (int i = 2; i <= lim; i++) {
            int p = spf[i], q = spf[i / p];
            if (p * q == i && p != q && q != 1) c++;
            else if (spf[i] == i && Math.pow(i, 8) <= n) c++;
        }
        return c;
    }
}
