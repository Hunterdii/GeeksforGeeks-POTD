class Solution {
    public int maxGold(int[][] mat) {
        int n = mat.length, m = mat[0].length;
        for (int j = m - 2; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                int mx = 0;
                for (int di = -1; di <= 1; di++) {
                    int ni = i + di;
                    if (ni >= 0 && ni < n) mx = Math.max(mx, mat[ni][j + 1]);
                }
                mat[i][j] += mx;
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) res = Math.max(res, mat[i][0]);
        return res;
    }
}
