class Solution {
    public ArrayList<String> ratInMaze(int[][] m) {
        ArrayList<String> res = new ArrayList<>();
        int n = m.length;
        if (m[0][0] == 0 || m[n-1][n-1] == 0) return res;
        solve(0, 0, m, n, "", res);
        return res;
    }
    
    void solve(int i, int j, int[][] m, int n, String p, ArrayList<String> res) {
        if (i == n-1 && j == n-1) {
            res.add(p);
            return;
        }
        m[i][j] = 0;
        if (i+1 < n && m[i+1][j] == 1) solve(i+1, j, m, n, p+'D', res);
        if (j-1 >= 0 && m[i][j-1] == 1) solve(i, j-1, m, n, p+'L', res);
        if (j+1 < n && m[i][j+1] == 1) solve(i, j+1, m, n, p+'R', res);
        if (i-1 >= 0 && m[i-1][j] == 1) solve(i-1, j, m, n, p+'U', res);
        m[i][j] = 1;
    }
}
