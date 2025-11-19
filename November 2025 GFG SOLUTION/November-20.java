class Solution {
    public int minCost(String s, String t, char[][] transform, int[] cost) {
        final int INF = (int)1e9;
        int[][] d = new int[26][26];
        for (int i = 0; i < 26; i++) {
            Arrays.fill(d[i], INF);
            d[i][i] = 0;
        }
        for (int i = 0; i < transform.length; i++)
            d[transform[i][0] - 'a'][transform[i][1] - 'a'] = Math.min(d[transform[i][0] - 'a'][transform[i][1] - 'a'], cost[i]);
        for (int k = 0; k < 26; k++)
            for (int i = 0; i < 26; i++)
                for (int j = 0; j < 26; j++)
                    if (d[i][k] < INF && d[k][j] < INF)
                        d[i][j] = Math.min(d[i][j], d[i][k] + d[k][j]);
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == t.charAt(i)) continue;
            int mn = INF, a = s.charAt(i) - 'a', b = t.charAt(i) - 'a';
            for (int c = 0; c < 26; c++)
                if (d[a][c] < INF && d[b][c] < INF)
                    mn = Math.min(mn, d[a][c] + d[b][c]);
            if (mn == INF) return -1;
            res += mn;
        }
        return res;
    }
}
