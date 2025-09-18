class Solution {
    public ArrayList<Integer> nextGreater(int[] arr) {
        int n = arr.length;
        ArrayList<Integer> res = new ArrayList<>(Collections.nCopies(n, -1));
        Stack<Integer> stk = new Stack<>();
        for (int i = 0; i < 2 * n; i++) {
            while (!stk.isEmpty() && arr[stk.peek()] < arr[i % n]) {
                res.set(stk.pop(), arr[i % n]);
            }
            if (i < n) stk.push(i);
        }
        return res;
    }
}
