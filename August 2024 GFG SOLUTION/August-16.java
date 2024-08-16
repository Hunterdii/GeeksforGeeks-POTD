//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;
import java.lang.*;

class Driver {
    public static void main(String args[]) throws IOException {
        // reading input using BufferedReader class
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));

        // reading total testcases
        int t = Integer.parseInt(read.readLine());

        while (t-- > 0) {
            // reading length of line segment
            int n = Integer.parseInt(read.readLine().trim());

            // reading 3 segment lengths
            String str[] = read.readLine().trim().split(" ");

            int x = Integer.parseInt(str[0]);
            int y = Integer.parseInt(str[1]);
            int z = Integer.parseInt(str[2]);

            // calling method maximizeCuts() of class Solution()
            // and printinting the result
            System.out.println(new Solution().maximizeCuts(n, x, y, z));
        }
    }
}

// } Driver Code Ends

// User function Template for Java

class Solution {
    public int maximizeCuts(int n, int x, int y, int z) {
        int[] dp = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            dp[i] = -1;
        }

        for (int i = 0; i <= n; i++) {
            if (dp[i] != -1) {
                if (i + x <= n)
                    dp[i + x] = Math.max(dp[i + x], dp[i] + 1);
                if (i + y <= n)
                    dp[i + y] = Math.max(dp[i + y], dp[i] + 1);
                if (i + z <= n)
                    dp[i + z] = Math.max(dp[i + z], dp[i] + 1);
            }
        }
        return dp[n] == -1 ? 0 : dp[n];
    }
}
