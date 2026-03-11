class Solution {
    public int sumSubMins(int[] arr) {
        int n = arr.length, mod = 1000000007;
        long res = 0;
        int[] left = new int[n], right = new int[n];
        int[] st = new int[n];
        int top = -1;
        for (int i = 0; i < n; i++) {
            while (top >= 0 && arr[st[top]] >= arr[i]) top--;
            left[i] = top < 0 ? -1 : st[top];
            st[++top] = i;
        }
        top = -1;
        for (int i = n - 1; i >= 0; i--) {
            while (top >= 0 && arr[st[top]] > arr[i]) top--;
            right[i] = top < 0 ? n : st[top];
            st[++top] = i;
        }
        for (int i = 0; i < n; i++)
            res = (res + (long)arr[i] * (i - left[i]) * (right[i] - i)) % mod;
        return (int)res;
    }
}
