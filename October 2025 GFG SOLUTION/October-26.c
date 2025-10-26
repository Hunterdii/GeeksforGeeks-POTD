void heapify(int arr[], int n, int i) {
    int smallest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] < arr[smallest]) smallest = l;
    if (r < n && arr[r] < arr[smallest]) smallest = r;
    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        heapify(arr, n, smallest);
    }
}

int minCost(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    int res = 0, size = n;
    while (size > 1) {
        int first = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapify(arr, size, 0);
        int second = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapify(arr, size, 0);
        int sum = first + second;
        res += sum;
        arr[size] = sum;
        size++;
        heapify(arr, size, 0);
    }
    return res;
}
