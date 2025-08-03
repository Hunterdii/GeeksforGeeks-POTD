class Solution {
    public ArrayList<ArrayList<Integer>> applyDiff2D(int[][] mat, int[][] opr) {
        int n = mat.length, m = mat[0].length;
        long[][] d = new long[n + 1][m + 1];
        
        for (int[] op : opr) {
            int v = op[0], r1 = op[1], c1 = op[2], r2 = op[3], c2 = op[4];
            d[r1][c1] += v;
            d[r1][c2 + 1] -= v;
            d[r2 + 1][c1] -= v;
            d[r2 + 1][c2 + 1] += v;
        }
        
        ArrayList<ArrayList<Integer>> res = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            ArrayList<Integer> row = new ArrayList<>();
            for (int j = 0; j < m; j++) {
                if (i > 0) d[i][j] += d[i - 1][j];
                if (j > 0) d[i][j] += d[i][j - 1];
                if (i > 0 && j > 0) d[i][j] -= d[i - 1][j - 1];
                row.add(mat[i][j] + (int)d[i][j]);
            }
            res.add(row);
        }
        return res;
    }
}
