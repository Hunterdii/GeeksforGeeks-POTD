class Solution {
    int smallestDivisor(int[] arr, int k) {
        int l = 1, h = Arrays.stream(arr).max().getAsInt();
        while (l < h) {
            int m = l + (h - l) / 2, s = 0;
            for (int x : arr)
                s += (x + m - 1) / m;
            if (s <= k) h = m;
            else l = m + 1;
        }
        return l;
    }
}
