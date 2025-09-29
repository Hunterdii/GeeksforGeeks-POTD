class Solution {
    public int maxSubarrSum(int[] arr, int a, int b) {
        int n = arr.length, res = Integer.MIN_VALUE;
        int[] pre = new int[n + 1];
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + arr[i];
        Deque<Integer> dq = new ArrayDeque<>();
        for (int i = a; i <= n; i++) {
            int l = Math.max(0, i - b), r = i - a;
            while (!dq.isEmpty() && pre[dq.peekLast()] >= pre[r]) dq.pollLast();
            dq.offerLast(r);
            while (!dq.isEmpty() && dq.peekFirst() < l) dq.pollFirst();
            res = Math.max(res, pre[i] - pre[dq.peekFirst()]);
        }
        return res;
    }
}
