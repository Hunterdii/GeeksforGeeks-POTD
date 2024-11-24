//{ Driver Code Starts
import java.io.*;
import java.util.*;

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

            int[] a = IntArray.input(br, 2);

            int[][] mat = IntMatrix.input(br, a[0], a[1]);

            Solution obj = new Solution();
            int res = obj.findShortestPath(mat);

            System.out.println(res);
        }
    }
}

// } Driver Code Ends


class Solution {
    static int findShortestPath(int[][] mat) {
        int n = mat.length, m = mat[0].length;
        int[] d = {1, -1, 0, 0};

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (mat[i][j] == 0) {
                    for (int k = 0; k < 4; k++) {
                        int x = i + d[k], y = j + d[3 - k];
                        if (x >= 0 && x < n && y >= 0 && y < m && mat[x][y] == 1)
                            mat[x][y] = 2;
                    }
                }

        Queue<int[]> q = new LinkedList<>();
        for (int i = 0; i < n; i++)
            if (mat[i][0] == 1) {
                mat[i][0] = 2;
                q.add(new int[]{i, 0});
            }

        int ans = 1;

        while (!q.isEmpty()) {
            int s = q.size();
            while (s-- > 0) {
                int[] current = q.poll();
                int i = current[0], j = current[1];
                if (j == m - 1)
                    return ans; // Found shortest path
                for (int k = 0; k < 4; k++) {
                    int x = i + d[k], y = j + d[3 - k];
                    if (x >= 0 && x < n && y >= 0 && y < m && mat[x][y] == 1) {
                        mat[x][y] = 2;
                        q.add(new int[]{x, y});
                    }
                }
            }
            ans++;
        }
        return -1;
    }
}

