class Solution {
    public boolean searchMatrix(int[][] mat, int x) {
        int n = mat.length, m = mat[0].length;
        int l = 0, r = n * m - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = mat[mid / m][mid % m];
            if (val == x) return true;
            if (mat[l / m][l % m] <= val) {
                if (mat[l / m][l % m] <= x && x < val) r = mid - 1;
                else l = mid + 1;
            } else {
                if (val < x && x <= mat[r / m][r % m]) l = mid + 1;
                else r = mid - 1;
            }
        }
        return false;
    }
}
