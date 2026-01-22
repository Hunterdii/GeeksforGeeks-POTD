class Solution {
    public int subarrayRanges(int[] a) {
        int n = a.length;
        long res = 0;
        Stack<Integer> s = new Stack<>();
        for (int i = 0; i <= n; i++) {
            while (!s.isEmpty() && (i == n || a[s.peek()] > a[i])) {
                int j = s.pop();
                int k = s.isEmpty() ? -1 : s.peek();
                res -= (long)a[j] * (i - j) * (j - k);
            }
            s.push(i);
        }
        s.clear();
        for (int i = 0; i <= n; i++) {
            while (!s.isEmpty() && (i == n || a[s.peek()] < a[i])) {
                int j = s.pop();
                int k = s.isEmpty() ? -1 : s.peek();
                res += (long)a[j] * (i - j) * (j - k);
            }
            s.push(i);
        }
        return (int)res;
    }
}
