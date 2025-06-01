class Solution {
    int countPairs(int[][] a, int[][] b, int x) {
        int r1 = 0, c1 = 0, r2 = b.length - 1, c2 = b[0].length - 1, cnt = 0;
        while (r1 < a.length && r2 >= 0) {
            int sum = a[r1][c1] + b[r2][c2];
            if (sum == x) { cnt++; c1++; c2--; }
            else if (sum < x) c1++;
            else c2--;
            if (c1 == a[0].length) { c1 = 0; r1++; }
            if (c2 < 0) { c2 = b[0].length - 1; r2--; }
        }
        return cnt;
    }
}
