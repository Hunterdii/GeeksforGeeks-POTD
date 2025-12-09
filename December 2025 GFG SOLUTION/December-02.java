class Solution {
    public int maxScore(String s, char[][] jumps) {
        int n = s.length();
        List<char[]> j = new ArrayList<>();
        for (char[] x : jumps) j.add(x);
        for (char c = 'a'; c <= 'z'; c++) j.add(new char[]{c, c});
        int[][] nxt = new int[n][26];
        int[] last = new int[26];
        Arrays.fill(last, -1);
        for (int i = n - 1; i >= 0; i--) {
            System.arraycopy(last, 0, nxt[i], 0, 26);
            last[s.charAt(i) - 'a'] = i;
        }
        List<List<Integer>> ch = new ArrayList<>();
        for (int i = 0; i < 26; i++) ch.add(new ArrayList<>());
        for (char[] x : j) ch.get(x[0] - 'a').add((int)x[1]);
        int[] pre = new int[n + 1];
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + s.charAt(i);
        int[] dp = new int[n];
        for (int i = n - 2; i >= 0; i--) {
            for (int c : ch.get(s.charAt(i) - 'a')) {
                int k = nxt[i][c - 'a'];
                if (k != -1) dp[i] = Math.max(dp[i], pre[k] - pre[i + (c == s.charAt(i) ? 1 : 0)] + dp[k]);
            }
        }
        return dp[0];
    }
}
