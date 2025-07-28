class Solution {
    public static int balanceSums(int[][] mat) {
        int n = mat.length, max = 0, res = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) sum += mat[i][j];
            max = Math.max(sum, max);
        }
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) sum += mat[i][j];
            max = Math.max(sum, max);
        }
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) sum += mat[i][j];
            res += max - sum;
        }
        return res;
    }
}
