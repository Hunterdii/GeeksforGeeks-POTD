class Solution {
    int getLongestPrefix(String s) {
        int n = s.length(), l = 0, r = 0, ans = -1;
        int[] z = new int[n];
        for (int i = 1; i < n; i++) {
            if (i <= r) z[i] = Math.min(r - i + 1, z[i - l]);
            while (i + z[i] < n && s.charAt(z[i]) == s.charAt(i + z[i])) z[i]++;
            if (i + z[i] - 1 > r) { l = i; r = i + z[i] - 1; }
            if (z[i] == n - i) ans = i;
        }
        return ans;
    }
}
