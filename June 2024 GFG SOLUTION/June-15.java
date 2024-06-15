//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GfG {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            Solution ob = new Solution();
            System.out.println(ob.getCount(n));
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    int[][] a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -1}};
    long[][][] dp = new long[4][3][26];

    public long getCount(int n) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                Arrays.fill(dp[i][j], 0);
                if (a[i][j] != -1) {
                    dp[i][j][1] = 1;
                }
            }
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    if (a[i][j] != -1) {
                        dp[i][j][len] = dp[i][j][len - 1];
                        if (j + 1 < 3 && a[i][j + 1] != -1) {
                            dp[i][j][len] += dp[i][j + 1][len - 1];
                        }
                        if (j - 1 >= 0 && a[i][j - 1] != -1) {
                            dp[i][j][len] += dp[i][j - 1][len - 1];
                        }
                        if (i + 1 < 4 && a[i + 1][j] != -1) {
                            dp[i][j][len] += dp[i + 1][j][len - 1];
                        }
                        if (i - 1 >= 0 && a[i - 1][j] != -1) {
                            dp[i][j][len] += dp[i - 1][j][len - 1];
                        }
                    }
                }
            }
        }

        long ans = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if (a[i][j] != -1) {
                    ans += dp[i][j][n];
                }
            }
        }
        return ans;
    }
}
