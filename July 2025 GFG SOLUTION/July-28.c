int balanceSum(int n, int mat[][n]) {
    int max = 0, res = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) sum += mat[i][j];
        if (sum > max) max = sum;
    }
    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) sum += mat[i][j];
        if (sum > max) max = sum;
    }
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) sum += mat[i][j];
        res += max - sum;
    }
    return res;
}
