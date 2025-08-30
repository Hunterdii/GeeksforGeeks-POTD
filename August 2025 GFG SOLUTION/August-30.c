int celebrity(int **m, int n) {
    int c = 0;
    for (int i = 1; i < n; i++) if (m[c][i]) c = i;
    for (int i = 0; i < n; i++) if (i != c && (m[c][i] || !m[i][c])) return -1;
    return c;
}
