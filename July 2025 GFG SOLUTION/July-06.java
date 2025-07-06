class Solution {
    public ArrayList<Integer> topKSumPairs(int[] a, int[] b, int k) {
        int n = a.length;
        Arrays.sort(a); Arrays.sort(b);
        PriorityQueue<int[]> pq = new PriorityQueue<>((x, y) -> y[0] - x[0]);
        Set<String> vis = new HashSet<>();
        pq.add(new int[]{a[n - 1] + b[n - 1], n - 1, n - 1});
        vis.add((n - 1) + "#" + (n - 1));
        ArrayList<Integer> res = new ArrayList<>();
        while (res.size() < k) {
            int[] top = pq.poll();
            res.add(top[0]);
            int i = top[1], j = top[2];
            if (i > 0 && vis.add((i - 1) + "#" + j))
                pq.add(new int[]{a[i - 1] + b[j], i - 1, j});
            if (j > 0 && vis.add(i + "#" + (j - 1)))
                pq.add(new int[]{a[i] + b[j - 1], i, j - 1});
        }
        return res;
    }
}
