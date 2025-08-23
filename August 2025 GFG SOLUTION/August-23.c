int findPages(int arr[], int n, int k) {
    if (k > n) return -1;
    int l = arr[0], r = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > l) l = arr[i];
        r += arr[i];
    }
    while (l < r) {
        int m = l + (r - l) / 2;
        int s = 1, p = 0;
        for (int i = 0; i < n; i++) {
            if (p + arr[i] > m) { s++; p = arr[i]; }
            else p += arr[i];
        }
        s <= k ? (r = m) : (l = m + 1);
    }
    return l;
}
