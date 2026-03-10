class Solution {
    public int countSubarrays(int[] arr) {
        int n = arr.length, top = -1, ans = 0;
        int[] st = new int[n];
        for (int i = n - 1; i >= 0; i--) {
            while (top >= 0 && arr[st[top]] >= arr[i]) top--;
            ans += ((top < 0 ? n : st[top]) - i);
            st[++top] = i;
        }
        return ans;
    }
}
