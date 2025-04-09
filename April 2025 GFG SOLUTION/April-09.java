//{ Driver Code Starts
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        while (tc-- > 0) {
            int V = sc.nextInt();
            int E = sc.nextInt();
            int[][] edges = new int[E][2];
            for (int i = 0; i < E; i++) {
                edges[i][0] = sc.nextInt();
                edges[i][1] = sc.nextInt();
            }

            Solution obj = new Solution();
            ArrayList<Integer> ans = obj.articulationPoints(V, edges);
            Collections.sort(ans);
            for (int val : ans) {
                System.out.print(val + " ");
            }
            System.out.println();
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Solution {
    static ArrayList<Integer> articulationPoints(int V, int[][] edges) {
        ArrayList<Integer>[] adj = new ArrayList[V];
        for (int i = 0; i < V; i++) adj[i] = new ArrayList<>();
        for (int[] e : edges) {
            adj[e[0]].add(e[1]);
            adj[e[1]].add(e[0]);
        }
        int[] disc = new int[V], low = new int[V];
        boolean[] vis = new boolean[V], ap = new boolean[V];
        int[] time = {0};
        for (int i = 0; i < V; i++)
            if (!vis[i]) dfs(i, -1, adj, disc, low, vis, ap, time);
        ArrayList<Integer> res = new ArrayList<>();
        for (int i = 0; i < V; i++)
            if (ap[i]) res.add(i);
        if (res.isEmpty()) res.add(-1);
        return res;
    }

    static void dfs(int u, int p, ArrayList<Integer>[] adj, int[] disc, int[] low, boolean[] vis, boolean[] ap, int[] time) {
        vis[u] = true;
        disc[u] = low[u] = ++time[0];
        int children = 0;
        for (int v : adj[u]) {
            if (!vis[v]) {
                children++;
                dfs(v, u, adj, disc, low, vis, ap, time);
                low[u] = Math.min(low[u], low[v]);
                if (p != -1 && low[v] >= disc[u]) ap[u] = true;
            } else if (v != p)
                low[u] = Math.min(low[u], disc[v]);
        }
        if (p == -1 && children > 1) ap[u] = true;
    }
}
