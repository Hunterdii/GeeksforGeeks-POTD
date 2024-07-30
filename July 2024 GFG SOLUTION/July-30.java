//{ Driver Code Starts
// Initial Template for Java

import java.util.*;

class Rat {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int[][] a = new int[n][n];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) a[i][j] = sc.nextInt();

            Solution obj = new Solution();
            ArrayList<String> res = obj.findPath(a);
            Collections.sort(res);
            if (res.size() > 0) {
                for (int i = 0; i < res.size(); i++) System.out.print(res.get(i) + " ");
                System.out.println();
            } else {
                System.out.println(-1);
            }
        }
    }
}

// } Driver Code Ends


class Solution {
    private boolean[][] visited;
    private ArrayList<String> result;

    private void path(int[][] m, int x, int y, String dir, int n) {
        if (x == n - 1 && y == n - 1) {
            result.add(dir);
            return;
        }
        if (m[x][y] == 0 || visited[x][y]) return;

        visited[x][y] = true;
        if (x > 0) path(m, x - 1, y, dir + 'U', n);
        if (y > 0) path(m, x, y - 1, dir + 'L', n);
        if (x < n - 1) path(m, x + 1, y, dir + 'D', n);
        if (y < n - 1) path(m, x, y + 1, dir + 'R', n);
        visited[x][y] = false;
    }

    public ArrayList<String> findPath(int[][] mat) {
        int n = mat.length;
        visited = new boolean[n][n];
        result = new ArrayList<>();

        if (mat[0][0] == 0 || mat[n - 1][n - 1] == 0) return result;

        path(mat, 0, 0, "", n);
        Collections.sort(result);
        return result;
    }
}
