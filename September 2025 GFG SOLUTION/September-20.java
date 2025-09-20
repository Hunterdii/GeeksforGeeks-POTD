class Solution {
    public static int longestSubarray(int[] a) {
        int n = a.length, res = 0;
        int[] l = new int[n], r = new int[n];
        Arrays.fill(l, -1);
        Arrays.fill(r, n);
        Stack<Integer> s = new Stack<>();
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && a[s.peek()] <= a[i]) s.pop();
            if (!s.empty()) r[i] = s.peek();
            s.push(i);
        }
        s.clear();
        for (int i = 0; i < n; i++) {
            while (!s.empty() && a[s.peek()] <= a[i]) s.pop();
            if (!s.empty()) l[i] = s.peek();
            s.push(i);
            int len = r[i] - l[i] - 1;
            if (len >= a[i]) res = Math.max(res, len);
        }
        return res;
    }
}
