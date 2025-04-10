//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            int n = sc.nextInt();
            int[][] edge = new int[n][2];
            for (int i = 0; i < n; i++) {
                edge[i][0] = sc.nextInt();
                edge[i][1] = sc.nextInt();
            }
            Solution obj = new Solution();
            int res = obj.minCost(edge);

            System.out.println(res);
            System.out.println("~");
        }
    }
}

// } Driver Code Ends




class Solution {
    public int minCost(int[][] a) {
        int n = a.length, ans = 0;
        boolean[] vis = new boolean[n];
        int[] d = new int[n];
        Arrays.fill(d, Integer.MAX_VALUE);
        d[0] = 0;
        for (int i = 0; i < n; i++) {
            int m = Integer.MAX_VALUE, u = -1;
            for (int j = 0; j < n; j++)
                if (!vis[j] && d[j] < m) {
                    m = d[j];
                    u = j;
                }
            vis[u] = true;
            ans += m;
            for (int j = 0; j < n; j++)
                if (!vis[j])
                    d[j] = Math.min(d[j], Math.abs(a[u][0] - a[j][0]) + Math.abs(a[u][1] - a[j][1]));
        }
        return ans;
    }
}



