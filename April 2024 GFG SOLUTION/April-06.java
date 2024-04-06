//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) {

        // taking input using Scanner class
        Scanner sc = new Scanner(System.in);

        // taking total testcases
        int t = sc.nextInt();

        while (t-- > 0) {

            // taking total number of stairs
            int n = sc.nextInt();

            // creating an object of class DynamicProgramming
            Solution obj = new Solution();

            // calling method of class countWays()
            // of class DynamicProgramming
            System.out.println(obj.countWays(n));
        }
    }
}

// } Driver Code Ends

1)
class Solution {
    long countWays(int n) {
        long prev = 1;
        long current = 1;

        for (int i = 2; i <= n; i++) {
            long temp = current;
            current = current + (i % 2 == 0 ? 1 : 0);
            prev = temp;
        }
        return current;
    }
}

2)
class Solution {
    long countWays(int n) {
        long[] dp = new long[n + 1];

        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + (i % 2 == 0 ? 1 : 0);
        }
        return dp[n];
    }
}




