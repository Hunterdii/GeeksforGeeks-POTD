class Solution {
    public int countSquare(int[][] mat, int x) {
        int n = mat.length, m = mat[0].length, cnt = 0;
        int[][] pre = new int[n + 1][m + 1];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                pre[i][j] = mat[i-1][j-1] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
        for (int sz = 1; sz <= Math.min(n, m); sz++)
            for (int i = sz; i <= n; i++)
                for (int j = sz; j <= m; j++)
                    if (pre[i][j] - pre[i-sz][j] - pre[i][j-sz] + pre[i-sz][j-sz] == x)
                        cnt++;
        return cnt;
    }
}
