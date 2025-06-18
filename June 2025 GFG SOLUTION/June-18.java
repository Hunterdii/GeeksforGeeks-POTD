class Solution {
    public ArrayList<ArrayList<String>> palinParts(String s) {
        int n = s.length();
        boolean[][] d = new boolean[n][n];
        for (int i = 0; i < n; i++) d[i][i] = true;
        for (int i = 0; i < n - 1; i++) d[i][i + 1] = s.charAt(i) == s.charAt(i + 1);
        for (int l = 3; l <= n; l++)
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                d[i][j] = s.charAt(i) == s.charAt(j) && d[i + 1][j - 1];
            }
        ArrayList<ArrayList<String>> r = new ArrayList<>();
        ArrayList<String> c = new ArrayList<>();
        dfs(0, s, d, c, r);
        return r;
    }

    void dfs(int i, String s, boolean[][] d, ArrayList<String> c, ArrayList<ArrayList<String>> r) {
        if (i == s.length()) { r.add(new ArrayList<>(c)); return; }
        for (int j = i; j < s.length(); j++)
            if (d[i][j]) {
                c.add(s.substring(i, j + 1));
                dfs(j + 1, s, d, c, r);
                c.remove(c.size() - 1);
            }
    }
}
