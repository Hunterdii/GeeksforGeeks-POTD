class Solution {
    public ArrayList<ArrayList<Integer>> knightTour(int n) {
        int[][] b = new int[n][n];
        for (int[] r : b) Arrays.fill(r, -1);
        int[] dx = {2, 1, -1, -2, -2, -1, 1, 2}, dy = {1, 2, 2, 1, -1, -2, -2, -1};
        b[0][0] = 0;
        if (solve(0, 0, 1, n, b, dx, dy)) {
            ArrayList<ArrayList<Integer>> res = new ArrayList<>();
            for (int[] r : b) {
                ArrayList<Integer> row = new ArrayList<>();
                for (int v : r) row.add(v);
                res.add(row);
            }
            return res;
        }
        return new ArrayList<>();
    }
    boolean solve(int x, int y, int s, int n, int[][] b, int[] dx, int[] dy) {
        if (s == n * n) return true;
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n && b[nx][ny] == -1) {
                b[nx][ny] = s;
                if (solve(nx, ny, s + 1, n, b, dx, dy)) return true;
                b[nx][ny] = -1;
            }
        }
        return false;
    }
}
