class Solution {
    public int maxSum(String s) {
        int n = s.length();
        int[] d = manacher(s);
        int[] L = new int[n], R = new int[n];
        for (int i = 0; i < n; i++) {
            int len = d[2 * i + 2];
            L[i + len / 2] = Math.max(L[i + len / 2], len);
            R[i - len / 2] = Math.max(R[i - len / 2], len);
        }
        for (int i = n - 2; i >= 0; i--) L[i] = Math.max(L[i], L[i + 1] - 2);
        for (int i = 1; i < n; i++) L[i] = Math.max(L[i], L[i - 1]);
        for (int i = 1; i < n; i++) R[i] = Math.max(R[i], R[i - 1] - 2);
        for (int i = n - 2; i >= 0; i--) R[i] = Math.max(R[i], R[i + 1]);
        int ans = 1;
        for (int i = 0; i + 1 < n; i++) ans = Math.max(ans, L[i] + R[i + 1]);
        return ans;
    }
    int[] manacher(String s) {
        StringBuilder t = new StringBuilder("@");
        for (char c : s.toCharArray()) t.append("#").append(c);
        t.append("#$");
        int m = t.length(), l = 0, r = 0;
        int[] d = new int[m];
        for (int i = 1; i < m - 1; i++) {
            if (i < r) d[i] = Math.min(r - i, d[l + r - i]);
            while (t.charAt(i - d[i] - 1) == t.charAt(i + d[i] + 1)) d[i]++;
            if (i + d[i] > r) { l = i - d[i]; r = i + d[i]; }
        }
        return d;
    }
}
