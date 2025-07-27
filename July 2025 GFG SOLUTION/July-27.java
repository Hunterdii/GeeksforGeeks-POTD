class Solution {
    public void setMatrixZeroes(int[][] mat) {
        int n = mat.length, m = mat[0].length;
        boolean row0 = false, col0 = false;
        for (int i = 0; i < n; i++) if (mat[i][0] == 0) col0 = true;
        for (int j = 0; j < m; j++) if (mat[0][j] == 0) row0 = true;
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                if (mat[i][j] == 0)
                    mat[i][0] = mat[0][j] = 0;
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                if (mat[i][0] == 0 || mat[0][j] == 0)
                    mat[i][j] = 0;
        if (row0) Arrays.fill(mat[0], 0);
        if (col0) for (int i = 0; i < n; i++) mat[i][0] = 0;
    }
}
