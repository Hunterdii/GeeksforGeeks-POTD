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

class IntArray {
    public static int[] input(BufferedReader br, int n) throws IOException {
        String[] s = br.readLine().trim().split(" ");
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = Integer.parseInt(s[i]);

        return a;
    }

    public static void print(int[] a) {
        for (int e : a) System.out.print(e + " ");
        System.out.println();
    }

    public static void print(ArrayList<Integer> a) {
        for (int e : a) System.out.print(e + " ");
        System.out.println();
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {

            int q;
            q = Integer.parseInt(br.readLine());

            int[][] queries = IntMatrix.input(br, q, 2);

            Solution obj = new Solution();
            ArrayList<Integer> res = obj.constructList(q, queries);

            IntArray.print(res);
        }
    }
}

// } Driver Code Ends



class Solution {
    public ArrayList<Integer> constructList(int q, int[][] queries) {
        int xr = 0;
        ArrayList<Integer> results = new ArrayList<>();
        for (int i = q - 1; i >= 0; --i) {
            if (queries[i][0] == 0) {
                results.add(queries[i][1] ^ xr);
            } else {
                xr ^= queries[i][1];
            }
        }
        results.add(xr);
        Collections.sort(results);
        return results;
    }
}
