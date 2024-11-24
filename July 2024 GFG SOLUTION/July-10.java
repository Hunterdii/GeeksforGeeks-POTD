//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int mat[][] = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    mat[i][j] = sc.nextInt();
                }
            }
            Solution ob = new Solution();
            System.out.println(ob.maxSquare(n, m, mat));
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    static int maxSquare(int n, int m, int mat[][]) {
        int[] dp = new int[m];
        int maxsize = 0, prev = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int temp = dp[j];
                if (i == 0 || j == 0) {
                    dp[j] = mat[i][j];
                } else if (mat[i][j] == 1) {
                    dp[j] = Math.min(Math.min(dp[j], dp[j - 1]), prev) + 1;
                } else {
                    dp[j] = 0;
                }
                maxsize = Math.max(maxsize, dp[j]);
                prev = temp;
            }
        }
        return maxsize;
    }
}
