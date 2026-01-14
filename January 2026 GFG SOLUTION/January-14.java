class Solution {
    public int catchThieves(char[] arr, int k) {
        int n = arr.length, p = 0, t = 0, cnt = 0;
        while (p < n && t < n) {
            while (p < n && arr[p] != 'P') p++;
            while (t < n && arr[t] != 'T') t++;
            if (p < n && t < n && Math.abs(p - t) <= k) {
                cnt++;
                p++;
                t++;
            } else if (t < n && t < p) t++;
            else if (p < n && p < t) p++;
        }
        return cnt;
    }
}
