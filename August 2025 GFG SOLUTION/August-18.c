int hIndex(int* citations, int citationsSize) {
    int n = citationsSize;
    int* bucket = (int*)calloc(n + 1, sizeof(int));
    
    for (int i = 0; i < n; i++) 
        bucket[citations[i] > n ? n : citations[i]]++;
    
    int count = 0;
    for (int i = n; i >= 0; i--) {
        count += bucket[i];
        if (count >= i) {
            free(bucket);
            return i;
        }
    }
    free(bucket);
    return 0;
}
