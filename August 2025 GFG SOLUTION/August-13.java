class Solution {
    public int minSoldiers(int[] arr, int k) {
        int need = (arr.length + 1) / 2, total = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int x : arr) pq.offer(x % k == 0 ? 0 : k - x % k);
        while (need-- > 0) total += pq.poll();
        return total;
    }
}
