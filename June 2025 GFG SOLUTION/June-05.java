class Solution {
    public int countPaths(int[][] E, int V, int S, int D) {
        List<List<Integer>> G = new ArrayList<>();
        int[] I = new int[V], dp = new int[V];
        for (int i = 0; i < V; i++) G.add(new ArrayList<>());
        for (int[] e : E) {
            G.get(e[0]).add(e[1]);
            I[e[1]]++;
        }
        Queue<Integer> Q = new ArrayDeque<>();
        for (int i = 0; i < V; i++) if (I[i] == 0) Q.add(i);
        List<Integer> T = new ArrayList<>();
        while (!Q.isEmpty()) {
            int u = Q.poll(); T.add(u);
            for (int v : G.get(u)) if (--I[v] == 0) Q.add(v);
        }
        dp[D] = 1;
        for (int i = V - 1; i >= 0; i--)
            for (int v : G.get(T.get(i))) dp[T.get(i)] += dp[v];
        return dp[S];
    }
}
