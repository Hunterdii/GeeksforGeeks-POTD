//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;


// } Driver Code Ends

// User function Template for Java

class Solution {
    public ArrayList<Integer> bfs(ArrayList<ArrayList<Integer>> adj) {
        ArrayList<Integer> r = new ArrayList<>();
        boolean[] v = new boolean[adj.size()];
        Queue<Integer> q = new LinkedList<>();
        q.add(0);
        v[0] = true;
        
        while (!q.isEmpty()) {
            int i = q.poll();
            r.add(i);
            for (int j : adj.get(i)) {
                if (!v[j]) {
                    v[j] = true;
                    q.add(j);
                }
            }
        }
        return r;
    }
}

//{ Driver Code Starts.

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());

        while (tc-- > 0) {
            int V = Integer.parseInt(br.readLine().trim());
            ArrayList<ArrayList<Integer>> adj = new ArrayList<>();

            for (int i = 0; i < V; i++) {
                String[] input = br.readLine().trim().split(" ");
                ArrayList<Integer> node = new ArrayList<>();
                for (String s : input) {
                    if (!s.isEmpty()) {
                        node.add(Integer.parseInt(s));
                    }
                }
                adj.add(node);
            }

            Solution obj = new Solution();
            ArrayList<Integer> ans = obj.bfs(adj);
            for (int num : ans) {
                System.out.print(num + " ");
            }
            System.out.println();
            System.out.println("~");
        }
    }
}

// } Driver Code Ends
