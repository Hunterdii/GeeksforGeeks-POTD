class Solution {
    public int minOperations(int[] arr) {
        double s = 0, t;
        PriorityQueue<Double> q = new PriorityQueue<>(Collections.reverseOrder());
        for (int x : arr) {
            s += x;
            q.offer((double) x);
        }
        t = s / 2;
        int ops = 0;
        while (s > t) {
            double x = q.poll();
            s -= x / 2;
            q.offer(x / 2);
            ops++;
        }
        return ops;
    }
}
