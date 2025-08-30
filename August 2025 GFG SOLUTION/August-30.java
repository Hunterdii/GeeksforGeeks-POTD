class Solution {
    public int celebrity(int m[][]) {
        int n = m.length, c = 0;
        for (int i = 1; i < n; i++) if (m[c][i] == 1) c = i;
        for (int i = 0; i < n; i++) if (i != c && (m[c][i] == 1 || m[i][c] == 0)) return -1;
        return c;
    }
}
