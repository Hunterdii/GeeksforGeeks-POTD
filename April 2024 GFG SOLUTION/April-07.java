//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
class GfG
{
    public static void main(String args[])
        {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0)
                {
                    int n = sc.nextInt();
                    int m = sc.nextInt();
                    int a[] = new int[n];
                    int b[] = new int[m];
                    for(int i = 0;i<n;i++)
                        a[i] = sc.nextInt();
                    for(int i = 0;i<m;i++)
                        b[i] = sc.nextInt();    
                    Solution ob = new Solution();
                    System.out.println(ob.maxDotProduct(n, m, a, b));
                }
        }
}    
// } Driver Code Ends


//User function Template for Java

class Solution {
    public int maxDotProduct(int n, int m, int a[], int b[]) { 
        int[][] dp = new int[n + 1][m + 1];
        for (int[] row : dp)
            Arrays.fill(row, -1);
        return solve(n, m, a, b, dp);
    }

    public int solve(int n, int m, int a[], int b[], int[][] dp) {
        if (m == 0) {
            return 0;
        }
        if (n < m) {
            return Integer.MIN_VALUE;
        }
        if (dp[n][m] != -1) {
            return dp[n][m];
        }
        int t2 = solve(n - 1, m, a, b, dp);
        int t3 = a[n - 1] * b[m - 1] + solve(n - 1, m - 1, a, b, dp);
        return dp[n][m] = Math.max(t2, t3);
    }
}
