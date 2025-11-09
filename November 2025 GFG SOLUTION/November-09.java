class Solution {
    int[][][] dp;
    int[][] mat;
    int n, m;
    
    int solve(int i1, int j1, int j2) {
        int i2 = i1 + j1 - j2;
        if (i1 >= n || i2 >= n || j1 >= m || j2 >= m || i2 < 0) return (int)-1e8;
        if (mat[i1][j1] == -1 || mat[i2][j2] == -1) return (int)-1e8;
        if (i1 == n - 1 && j1 == m - 1 && j2 == m - 1) return mat[i1][j1];
        if (dp[i1][j1][j2] != -1) return dp[i1][j1][j2];
        int res = (int)-1e8;
        for (int d1 = 0; d1 < 2; d1++)
            for (int d2 = 0; d2 < 2; d2++)
                res = Math.max(res, solve(i1 + 1 - d1, j1 + d1, j2 + d2));
        res += mat[i1][j1];
        if (i1 != i2) res += mat[i2][j2];
        return dp[i1][j1][j2] = res;
    }
    
    public int chocolatePickup(int[][] mat) {
        this.mat = mat;
        n = mat.length;
        m = mat[0].length;
        dp = new int[n][m][m];
        for (int[][] a : dp) for (int[] b : a) Arrays.fill(b, -1);
        return Math.max(0, solve(0, 0, 0));
    }
}
