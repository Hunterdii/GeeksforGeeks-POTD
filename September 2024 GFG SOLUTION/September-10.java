//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine().trim());
        while (t-- > 0) {
            String A[] = in.readLine().trim().split(" ");
            int N = Integer.parseInt(A[0]);
            A = in.readLine().trim().split(" ");

            Solution ob = new Solution();
            System.out.println(ob.isCircle(A));
        }
    }
}
// } Driver Code Ends


// User function Template for Java
class Solution {
    public void dfs(int node, ArrayList<Integer>[] adj, boolean[] visited) {
        visited[node] = true;
        for (int u : adj[node]) {
            if (!visited[u]) {
                dfs(u, adj, visited);
            }
        }
    }

    public boolean isConnected(ArrayList<Integer>[] adj, int[] indegree) {
        boolean[] visited = new boolean[26];
        int start = -1;
        
        for (int i = 0; i < 26; i++) {
            if (indegree[i] > 0) {
                start = i;
                break;
            }
        }

        if (start == -1) return true;

        dfs(start, adj, visited);

        for (int i = 0; i < 26; i++) {
            if (indegree[i] > 0 && !visited[i])
                return false;
        }

        return true;
    }

    public int isCircle(String[] arr) {
        int N = arr.length;
        ArrayList<Integer>[] adj = new ArrayList[26];
        ArrayList<Integer>[] adjr = new ArrayList[26];
        int[] indegree = new int[26], outdegree = new int[26];

        for (int i = 0; i < 26; i++) {
            adj[i] = new ArrayList<>();
            adjr[i] = new ArrayList<>();
        }

        for (int i = 0; i < N; i++) {
            int u = arr[i].charAt(0) - 'a';
            int v = arr[i].charAt(arr[i].length() - 1) - 'a';
            adj[u].add(v);
            adjr[v].add(u);
            outdegree[u]++;
            indegree[v]++;
        }

        for (int i = 0; i < 26; i++) {
            if (indegree[i] != outdegree[i])
                return 0;
        }

        if (!isConnected(adj, indegree))
            return 0;

        if (!isConnected(adjr, outdegree))
            return 0;

        return 1;
    }
}
