class Solution {
    public int shortCycle(int V, int[][] edges) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) adj.add(new ArrayList<>());
        for (int[] e : edges) {
            adj.get(e[0]).add(e[1]);
            adj.get(e[1]).add(e[0]);
        }
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < V; i++) {
            int[] d = new int[V];
            int[] p = new int[V];
            Arrays.fill(d, -1);
            Arrays.fill(p, -1);
            Queue<Integer> q = new LinkedList<>();
            d[i] = 0;
            q.offer(i);
            while (!q.isEmpty()) {
                int u = q.poll();
                for (int v : adj.get(u)) {
                    if (d[v] == -1) {
                        d[v] = d[u] + 1;
                        p[v] = u;
                        q.offer(v);
                    } else if (p[u] != v) res = Math.min(res, d[u] + d[v] + 1);
                }
            }
        }
        return res == Integer.MAX_VALUE ? -1 : res;
    }
}
