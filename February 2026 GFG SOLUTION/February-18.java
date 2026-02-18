class Solution {
    static int merge(int[] arr, int l, int m, int r) {
        int[] t = Arrays.copyOfRange(arr, l, r + 1);
        int i = 0, j = m - l + 1, k = l, cnt = 0, lsz = m - l + 1;
        while (i < lsz && j < t.length)
            if (t[i] <= t[j]) arr[k++] = t[i++];
            else { cnt += lsz - i; arr[k++] = t[j++]; }
        while (i < lsz) arr[k++] = t[i++];
        while (j < t.length) arr[k++] = t[j++];
        return cnt;
    }
    static int sort(int[] arr, int l, int r) {
        if (l >= r) return 0;
        int m = (l + r) / 2;
        return sort(arr, l, m) + sort(arr, m + 1, r) + merge(arr, l, m, r);
    }
    static int inversionCount(int[] arr) { return sort(arr, 0, arr.length - 1); }
}
