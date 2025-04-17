//{ Driver Code Starts
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = Integer.parseInt(sc.nextLine());

        while (t-- > 0) {
            int V = Integer.parseInt(sc.nextLine());
            int E = Integer.parseInt(sc.nextLine());

            List<int[]> edgeList = new ArrayList<>();

            for (int i = 0; i < E; i++) {
                String[] parts = sc.nextLine().split(" ");
                int u = Integer.parseInt(parts[0]);
                int v = Integer.parseInt(parts[1]);
                int w = Integer.parseInt(parts[2]);
                edgeList.add(new int[] {u, v, w});
                edgeList.add(new int[] {v, u, w});
            }

            int[][] edges = new int[edgeList.size()][3];
            for (int i = 0; i < edgeList.size(); i++) {
                edges[i] = edgeList.get(i);
            }

            Solution obj = new Solution();
            int res = obj.findMinCycle(V, edges);

            System.out.println(res);
        }

        sc.close();
    }
}

// } Driver Code Ends


class Solution {
    public int findMinCycle(int V, int[][] E) {
        List<int[]>[] A = new ArrayList[V];
        for (int i = 0; i < V; i++) A[i] = new ArrayList<>();
        for (int[] e : E) A[e[0]].add(new int[]{e[1], e[2]});
        int r = Integer.MAX_VALUE;
        for (int i = 0; i < V; i++) {
            int[] D = new int[V], P = new int[V];
            Arrays.fill(D, (int)1e9);
            Arrays.fill(P, -1);
            D[i] = 0;
            PriorityQueue<int[]> Q = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
            Q.add(new int[]{0, i});
            while (!Q.isEmpty()) {
                int[] t = Q.poll(); int d = t[0], u = t[1];
                for (int[] a : A[u]) {
                    int v = a[0], w = a[1];
                    if (D[v] > d + w) {
                        D[v] = d + w; P[v] = u; Q.add(new int[]{D[v], v});
                    } else if (P[u] != v && P[v] != u)
                        r = Math.min(r, D[u] + D[v] + w);
                }
            }
        }
        return r == Integer.MAX_VALUE ? -1 : r;
    }
}
