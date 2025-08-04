class Solution {
    public int maxRectSum(int mat[][]) {
        int m = mat.length, n = mat[0].length, res = Integer.MIN_VALUE;
        for (int l = 0; l < n; l++) {
            int[] temp = new int[m];
            for (int r = l; r < n; r++) {
                for (int i = 0; i < m; i++) temp[i] += mat[i][r];
                int sum = 0, maxSum = temp[0];
                for (int x : temp) {
                    sum = Math.max(x, sum + x);
                    maxSum = Math.max(maxSum, sum);
                }
                res = Math.max(res, maxSum);
            }
        }
        return res;
    }
}
