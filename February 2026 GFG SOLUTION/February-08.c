int maxProduct(int arr[], int n) {
    int mx = arr[0], mn = arr[0], r = arr[0], a, b;
    for (int i = 1; i < n; i++) {
        a = mx * arr[i]; b = mn * arr[i];
        mx = a > b ? (a > arr[i] ? a : arr[i]) : (b > arr[i] ? b : arr[i]);
        mn = a < b ? (a < arr[i] ? a : arr[i]) : (b < arr[i] ? b : arr[i]);
        r = r > mx ? r : mx;
    }
    return r;
}
