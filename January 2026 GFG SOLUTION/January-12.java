class Solution {
    public ArrayList<Integer> maxOfSubarrays(int[] arr, int k) {
        ArrayList<Integer> res = new ArrayList<>();
        Deque<Integer> dq = new ArrayDeque<>();
        for (int i = 0; i < arr.length; i++) {
            if (!dq.isEmpty() && dq.peekFirst() <= i - k) dq.pollFirst();
            while (!dq.isEmpty() && arr[dq.peekLast()] <= arr[i]) dq.pollLast();
            dq.offerLast(i);
            if (i >= k - 1) res.add(arr[dq.peekFirst()]);
        }
        return res;
    }
}
