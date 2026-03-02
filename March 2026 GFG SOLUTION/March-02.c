int maxWater(int* arr, int n) {
    int l = 0, r = n - 1, lmax = 0, rmax = 0, res = 0;
    while (l < r) {
        if (arr[l] < arr[r]) {
            lmax = lmax > arr[l] ? lmax : arr[l];
            res += lmax - arr[l++];
        } else {
            rmax = rmax > arr[r] ? rmax : arr[r];
            res += rmax - arr[r--];
        }
    }
    return res;
}
