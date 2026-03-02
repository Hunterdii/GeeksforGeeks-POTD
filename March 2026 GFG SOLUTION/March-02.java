class Solution {
    public int maxWater(int arr[]) {
        int l = 0, r = arr.length - 1, lmax = 0, rmax = 0, res = 0;
        while (l < r) {
            if (arr[l] < arr[r]) {
                lmax = Math.max(lmax, arr[l]);
                res += lmax - arr[l++];
            } else {
                rmax = Math.max(rmax, arr[r]);
                res += rmax - arr[r--];
            }
        }
        return res;
    }
}
