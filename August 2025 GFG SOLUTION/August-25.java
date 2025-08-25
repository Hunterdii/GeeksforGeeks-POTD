class Solution {
    public int maximizeMedian(int[] arr, int k) {
        Arrays.sort(arr);
        int n = arr.length;
        int left = (n % 2 == 1) ? arr[n/2] : (arr[n/2-1] + arr[n/2]) / 2;
        int right = left + k;
        int result = left;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canAchieve(arr, mid, k)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
    
    private boolean canAchieve(int[] arr, int target, int k) {
        int n = arr.length;
        long ops = 0;
        
        if (n % 2 == 1) {
            for (int i = n/2; i < n; i++) {
                if (arr[i] < target) {
                    ops += target - arr[i];
                    if (ops > k) return false;
                }
            }
        } else {
            long medianSum = (long)arr[n/2-1] + arr[n/2];
            if (2L * target > medianSum) {
                ops += 2L * target - medianSum;
                if (ops > k) return false;
            }
            for (int i = n/2+1; i < n; i++) {
                if (arr[i] < target) {
                    ops += target - arr[i];
                    if (ops > k) return false;
                }
            }
        }
        return true;
    }
}
