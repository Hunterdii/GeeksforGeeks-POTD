class Solution {
    public void nearlySorted(int[] arr, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int idx = 0, n = arr.length;
        for (int i = 0; i <= Math.min(k, n - 1); i++) pq.add(arr[i]);
        for (int i = k + 1; i < n; i++) {
            arr[idx++] = pq.poll();
            pq.add(arr[i]);
        }
        while (!pq.isEmpty()) arr[idx++] = pq.poll();
    }
}
