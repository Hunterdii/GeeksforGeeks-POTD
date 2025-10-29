class Solution {
    public int diameter(int V, int[][] edges) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) adj.add(new ArrayList<>());
        for (int[] e : edges) {
            adj.get(e[0]).add(e[1]);
            adj.get(e[1]).add(e[0]);
        }
        int[] first = bfs(0, adj);
        int[] second = bfs(first[0], adj);
        return second[1];
    }
    private int[] bfs(int src, List<List<Integer>> adj) {
        int n = adj.size();
        int[] dist = new int[n];
        Arrays.fill(dist, -1);
        Queue<Integer> q = new LinkedList<>();
        q.add(src);
        dist[src] = 0;
        int far = src, maxD = 0;
        while (!q.isEmpty()) {
            int u = q.poll();
            for (int v : adj.get(u)) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.add(v);
                    if (dist[v] > maxD) {
                        maxD = dist[v];
                        far = v;
                    }
                }
            }
        }
        return new int[]{far, maxD};
    }
}
