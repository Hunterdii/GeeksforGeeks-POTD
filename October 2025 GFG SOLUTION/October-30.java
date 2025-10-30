class Solution {
    public void fill(char[][] g) {
        int m = g.length, n = g[0].length;
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) if (g[i][j] == 'O') g[i][j] = '-';
        for (int i = 0; i < m; i++) { dfs(g, i, 0, m, n); dfs(g, i, n - 1, m, n); }
        for (int j = 0; j < n; j++) { dfs(g, 0, j, m, n); dfs(g, m - 1, j, m, n); }
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) if (g[i][j] == '-') g[i][j] = 'X';
    }
    void dfs(char[][] g, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || g[i][j] != '-') return;
        g[i][j] = 'O';
        dfs(g, i + 1, j, m, n); dfs(g, i - 1, j, m, n); dfs(g, i, j + 1, m, n); dfs(g, i, j - 1, m, n);
    }
}
