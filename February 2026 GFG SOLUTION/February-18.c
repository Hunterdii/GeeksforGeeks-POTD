int merge(int arr[], int temp[], int l, int r) {
    if (l >= r) return 0;
    int m = (l + r) / 2, cnt = 0;
    cnt += merge(arr, temp, l, m);
    cnt += merge(arr, temp, m + 1, r);
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r)
        arr[i] <= arr[j] ? (temp[k++] = arr[i++]) : (cnt += m - i + 1, temp[k++] = arr[j++]);
    while (i <= m) temp[k++] = arr[i++];
    while (j <= r) temp[k++] = arr[j++];
    for (i = l; i <= r; i++) arr[i] = temp[i];
    return cnt;
}

int countInversions(int arr[], int n) {
    int temp[n];
    return merge(arr, temp, 0, n - 1);
}
