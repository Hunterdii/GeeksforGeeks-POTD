class Solution {
    public int minDaysBloom(int[] arr, int k, int m) {
        if ((long) k * m > arr.length) return -1;
        int l = Arrays.stream(arr).min().getAsInt();
        int r = Arrays.stream(arr).max().getAsInt();
        while (l < r) {
            int mid = l + (r - l) / 2;
            int flowers = 0, bouquets = 0;
            for (int bloom : arr) {
                if (bloom <= mid) {
                    if (++flowers == k) {
                        bouquets++;
                        flowers = 0;
                    }
                } else flowers = 0;
            }
            if (bouquets >= m) r = mid;
            else l = mid + 1;
        }
        return l;
    }
}
