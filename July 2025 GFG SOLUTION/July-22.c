int missingNumber(int a[], int n) {
    for (int i = 0; i < n; i++) if (a[i] <= 0) a[i] = n + 1;
    for (int i = 0; i < n; i++) {
        int x = abs(a[i]);
        if (x <= n) a[x - 1] = -abs(a[x - 1]);
    }
    for (int i = 0; i < n; i++) if (a[i] > 0) return i + 1;
    return n + 1;
}
