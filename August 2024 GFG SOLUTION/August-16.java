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
    // Function to find the maximum number of cuts.
    public int maximizeCuts(int n, int x, int y, int z) {
        // Initialize a dp array of size n+1
        int[] dp = new int[n + 1];

        // Initialize the dp array to -1 for all lengths except 0
        for (int i = 1; i <= n; i++) {
            dp[i] = -1;
        }

        // Iterate through the dp array
        for (int i = 0; i <= n; i++) {
            // If current length i has a valid solution
            if (dp[i] != -1) {
                // Check if we can make a cut of length x, y, or z
                if (i + x <= n)
                    dp[i + x] = Math.max(dp[i + x], dp[i] + 1);
                if (i + y <= n)
                    dp[i + y] = Math.max(dp[i + y], dp[i] + 1);
                if (i + z <= n)
                    dp[i + z] = Math.max(dp[i + z], dp[i] + 1);
            }
        }

        // If dp[n] is still -1, return 0, meaning no cuts could be made
        return dp[n] == -1 ? 0 : dp[n];
    }
}