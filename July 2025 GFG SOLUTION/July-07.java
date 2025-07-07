class Solution {
    public ArrayList<Integer> nextLargerElement(int[] arr) {
        int n = arr.length;
        ArrayList<Integer> res = new ArrayList<>(Collections.nCopies(n, -1));
        Deque<Integer> st = new ArrayDeque<>();
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.isEmpty() && st.peek() <= arr[i % n]) st.pop();
            if (i < n && !st.isEmpty()) res.set(i, st.peek());
            st.push(arr[i % n]);
        }
        return res;
    }
}
