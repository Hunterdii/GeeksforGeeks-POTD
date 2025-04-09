class Solution {
    static int time = 0;
    static void dfs(int u, ArrayList<Integer> adj[], int[] disc, int[] low, int[] parent, boolean[] ap) {
        int children = 0;
        disc[u] = low[u] = time++;
        for (int v : adj[u]) {
            if (disc[v] == -1) {
                parent[v] = u;
                children++;
                dfs(v, adj, disc, low, parent, ap);
                low[u] = Math.min(low[u], low[v]);
                
                if (parent[u] == -1 && children > 1) {
                    ap[u] = true;
                }
                if (parent[u] != -1 && low[v] >= disc[u]) {
                    ap[u] = true;
                }
            }else if (v != parent[u]) {
                low[u] = Math.min(low[u], disc[v]);
            }
        }
    }
    static ArrayList<Integer> articulationPoints(int V, int[][] edges) {
        // code here
        ArrayList<Integer> adj[] = new ArrayList[V];
        for (int i = 0; i < V; i++) {
            adj[i] = new ArrayList<>();
        }
        for (int[] edge : edges) {
            adj[edge[0]].add(edge[1]);
            adj[edge[1]].add(edge[0]);
        }
        
        int[] disc = new int [V];
        int[] low = new int [V];
        int[] parent = new int [V];
        boolean[] ap = new boolean[V];
        Arrays.fill(disc, -1);
        Arrays.fill(parent, -1);
        Arrays.fill(low, -1);
        
        for (int i = 0; i < V; i++) {
            if (disc[i] == -1) {
                dfs(i, adj, disc, low, parent, ap);
            }
        }
        
        ArrayList<Integer> result = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            if (ap[i]) {
                result.add(i);
            }
        }
        
        if (result.size() == 0) {
            result.add(-1);
        }
        return result;
    }
}
