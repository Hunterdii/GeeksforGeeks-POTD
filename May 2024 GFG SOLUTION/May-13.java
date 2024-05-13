//{ Driver Code Starts
import java.io.*;
import java.util.*;

class IntMatrix {
    public static int[][] input(BufferedReader br, int n, int m) throws IOException {
        int[][] mat = new int[n][];

        for (int i = 0; i < n; i++) {
            String[] s = br.readLine().trim().split(" ");
            mat[i] = new int[s.length];
            for (int j = 0; j < s.length; j++) mat[i][j] = Integer.parseInt(s[j]);
        }

        return mat;
    }

    public static void print(int[][] m) {
        for (var a : m) {
            for (int e : a) System.out.print(e + " ");
            System.out.println();
        }
    }

    public static void print(ArrayList<ArrayList<Integer>> m) {
        for (var a : m) {
            for (int e : a) System.out.print(e + " ");
            System.out.println();
        }
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {

            int e;
            e = Integer.parseInt(br.readLine());

            int v;
            v = Integer.parseInt(br.readLine());

            int[][] edges = IntMatrix.input(br, e, 2);

            Solution obj = new Solution();
            int res = obj.findNumberOfGoodComponent(e, v, edges);

            System.out.println(res);
        }
    }
}

// } Driver Code Ends


class Solution {
    public static int findNumberOfGoodComponent(int e, int v, int[][] edges) {
        int[] visited = new int[v + 1];
        int ans = 0;

        // Build adjacency list
        List<Integer>[] adj = new ArrayList[v + 1];
        for (int i = 1; i <= v; i++) {
            adj[i] = new ArrayList<>();
        }
        for (int[] edge : edges) {
            adj[edge[0]].add(edge[1]);
            adj[edge[1]].add(edge[0]);
        }

        for (int i = 1; i <= v; i++) {
            if (visited[i] == 0) {
                int vertices = 0;
                int edgesCount = 0;

                Stack<Integer> stack = new Stack<>();
                stack.push(i);
                visited[i] = 1;

                while (!stack.isEmpty()) {
                    int node = stack.pop();
                    vertices++;
                    edgesCount += adj[node].size();

                    for (int neighbor : adj[node]) {
                        if (visited[neighbor] == 0) {
                            stack.push(neighbor);
                            visited[neighbor] = 1;
                        }
                    }
                }

                edgesCount /= 2;
                if (edgesCount == (vertices * (vertices - 1)) / 2) {
                    ans++;
                }
            }
        }
        return ans;
    }
}
