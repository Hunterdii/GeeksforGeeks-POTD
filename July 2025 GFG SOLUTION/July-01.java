class Solution {
    public int substrCount(String s, int k) {
        if (k > s.length()) return 0;
        int[] cnt = new int[26];
        int ans = 0, d = 0, n = s.length();
        for (int i = 0; i < k - 1; i++) if (++cnt[s.charAt(i)-'a'] == 1) d++;
        for (int i = k - 1; i < n; i++) {
            if (++cnt[s.charAt(i)-'a'] == 1) d++;
            if (d == k - 1) ans++;
            if (--cnt[s.charAt(i-k+1)-'a'] == 0) d--;
        }
        return ans;
    }
}
