class Solution {
    public int kokoEat(int[] arr, int k) {
        int lo = 1, hi = 0;
        for (int pile : arr) hi = Math.max(hi, pile);
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int hours = 0;
            for (int pile : arr) {
                hours += (pile + mid - 1) / mid;
            }
            if (hours <= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
}
