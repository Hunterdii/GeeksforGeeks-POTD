int cmp(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

int hIndex(int citations[], int citationsSize) {
    qsort(citations, citationsSize, sizeof(int), cmp);
    for (int i = 0; i < citationsSize; i++) {
        if (citations[i] < i + 1) return i;
    }
    return citationsSize;
}
