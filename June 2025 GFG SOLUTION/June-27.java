class Solution {
    public int getCount(int n) {
        int[][] p = new int[4][3], c = new int[4][3];
        for (int i = 0; i < 4; i++) for (int j = 0; j < 3; j++) p[i][j] = 1;
        p[3][0] = p[3][2] = 0;
        int[][] d = {{0,0},{0,1},{0,-1},{1,0},{-1,0}};
        for (int k = 2; k <= n; k++) {
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 3; j++) {
                    if (i==3&&(j==0||j==2)) continue;
                    c[i][j] = 0;
                    for (int[] v : d) {
                        int x = i + v[0], y = j + v[1];
                        if (x >= 0 && x < 4 && y >= 0 && y < 3) c[i][j] += p[x][y];
                    }
                }
            for (int i = 0; i < 4; i++) System.arraycopy(c[i], 0, p[i], 0, 3);
        }
        int ans = 0;
        for (int[] r : p) for (int v : r) ans += v;
        return ans;
    }
}
