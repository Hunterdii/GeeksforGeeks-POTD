class Solution {
    public int minCandy(int arr[]) {
        int n = arr.length, total = n, i = 1;
        while (i < n) {
            if (arr[i] == arr[i - 1]) { i++; continue; }
            int peak = 0;
            while (i < n && arr[i] > arr[i - 1]) { total += ++peak; i++; }
            int valley = 0;
            while (i < n && arr[i] < arr[i - 1]) { total += ++valley; i++; }
            total -= Math.min(peak, valley);
        }
        return total;
    }
}
