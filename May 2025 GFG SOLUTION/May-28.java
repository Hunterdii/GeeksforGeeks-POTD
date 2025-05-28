class Solution {
    public boolean ValidCorner(int[][] mat) {
        int n = mat.length, m = mat[0].length;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                int cnt = 0;
                for (int k = 0; k < m; k++)
                    cnt += mat[i][k] & mat[j][k];
                if (cnt > 1) return true;
            }
        return false;
    }
}
