class Solution {
    public static int minCost(int[] arr) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int x : arr) pq.add(x);
        int res = 0;
        while (pq.size() > 1) {
            int sum = pq.poll() + pq.poll();
            res += sum;
            pq.add(sum);
        }
        return res;
    }
}
