int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int* findUnion(int* a, int n, int* b, int m, int* returnSize) {
    int* res = (int*)malloc((n + m) * sizeof(int));
    int k = 0;
    for (int i = 0; i < n; i++) res[k++] = a[i];
    for (int i = 0; i < m; i++) res[k++] = b[i];
    qsort(res, k, sizeof(int), cmp);
    int j = 0;
    for (int i = 1; i < k; i++) {
        if (res[i] != res[j]) res[++j] = res[i];
    }
    *returnSize = j + 1;
    return res;
}
