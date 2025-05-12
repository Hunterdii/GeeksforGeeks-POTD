class Solution {
    public int mostBooked(int n, int[][] meetings) {
        // code here
        Arrays.sort(meetings, (a, b) -> Integer.compare(a[0], b[0]));
        PriorityQueue<Integer> free = new PriorityQueue<>();
        for (int i = 0; i < n; i++) free.offer(i);
        PriorityQueue<long[]> busy = new PriorityQueue<>((a, b) -> a[0] != b[0] ? Long.compare(a[0], b[0]) : Integer.compare((int)a[1], (int)b[1]));
        int[] count = new int[n];
        for (int[] m : meetings) {
            int start = m[0], end = m[1], duration = end - start;
            while (!busy.isEmpty() && busy.peek()[0] <= start)
                free.offer((int) busy.poll()[1]);
            if (!free.isEmpty()) {
                int room = free.poll();
                busy.offer(new long[] { end, room });
                count[room]++;
            } else {
                long[] next = busy.poll();
                busy.offer(new long[] { next[0] + duration, next[1] });
                count[(int) next[1]]++;
            }
        }
        int max = 0, res = 0;
        for (int i = 0; i < n; i++)
            if (count[i] > max) {
                max = count[i];
                res = i;
            }
        return res;
    }
}
