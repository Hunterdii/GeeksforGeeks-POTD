class Solution {
    public ArrayList<Integer> safeNodes(int V, int[][] edges) {
        int[] out = new int[V];
        List<List<Integer>> g = new ArrayList<>();
        for (int i = 0; i < V; i++) g.add(new ArrayList<>());
        for (int[] e : edges) { out[e[0]]++; g.get(e[1]).add(e[0]); }
        Queue<Integer> q = new LinkedList<>();
        boolean[] safe = new boolean[V];
        for (int i = 0; i < V; i++) if (out[i] == 0) { q.add(i); safe[i] = true; }
        while (!q.isEmpty()) {
            int u = q.poll();
            for (int v : g.get(u)) if (!safe[v] && --out[v] == 0) { q.add(v); safe[v] = true; }
        }
        ArrayList<Integer> res = new ArrayList<>();
        for (int i = 0; i < V; i++) if (safe[i]) res.add(i);
        return res;
    }
}
