class Solution {
    public int sumSubMins(int[] arr) {
        final int MOD = 1000000007;
        int n = arr.length;
        int[] left = new int[n];
        int[] right = new int[n];
        Deque<Integer> st = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            while (!st.isEmpty() && arr[st.peekLast()] >= arr[i]) st.pollLast();
            left[i] = st.isEmpty() ? i + 1 : i - st.peekLast();
            st.offerLast(i);
        }
        st.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.isEmpty() && arr[st.peekLast()] > arr[i]) st.pollLast();
            right[i] = st.isEmpty() ? n - i : st.peekLast() - i;
            st.offerLast(i);
        }
        long res = 0;
        for (int i = 0; i < n; i++) {
            res = (res + (long) arr[i] * left[i] * right[i]) % MOD;
        }
        return (int) res;
    }
}
