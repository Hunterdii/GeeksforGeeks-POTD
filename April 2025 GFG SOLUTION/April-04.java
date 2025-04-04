//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;

class GFG {
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
            boolean ans = obj.isCycle(V, edges);
            System.out.println(ans ? "true" : "false");
            System.out.println("~");
        }
        sc.close();
    }
}

// } Driver Code Ends


class Solution {
    public boolean isCycle(int V, int[][] edges) {
        int[] p = new int[V];
        Arrays.fill(p, -1);
        for (int[] e : edges) {
            int a = f(p, e[0]), b = f(p, e[1]);
            if (a == b) return true;
            if (p[a] > p[b]) { int t = a; a = b; b = t; }
            p[a] += p[b]; p[b] = a;
        }
        return false;
    }
    int f(int[] p, int x) {
        return p[x] < 0 ? x : (p[x] = f(p, p[x]));
    }
}
