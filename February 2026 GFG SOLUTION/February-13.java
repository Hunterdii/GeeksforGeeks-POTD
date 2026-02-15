class Solution {
    public int getCount(int n, int d) {
        int lo = 1, hi = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2, sum = 0, temp = mid;
            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }
            if (mid - sum >= d) hi = mid - 1;
            else lo = mid + 1;
        }
        return n - hi;
    }
}
