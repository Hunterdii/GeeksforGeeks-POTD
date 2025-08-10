class Solution {
    public int countPS(String s) {
        int n = s.length(), ans = 0;
        for (int i = 0; i < n; i++) {
            ans += expand(s, i - 1, i + 1); // odd length
            ans += expand(s, i, i + 1);     // even length
        }
        return ans;
    }

    private int expand(String s, int l, int r) {
        int cnt = 0, n = s.length();
        while (l >= 0 && r < n && s.charAt(l--) == s.charAt(r++)) cnt++;
        return cnt;
    }
}
