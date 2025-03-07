//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GfG {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            String s = sc.next();
            Solution obj = new Solution();
            System.out.println(obj.longestPalinSubseq(s));

            System.out.println("~");
        }
    }
}
// } Driver Code Ends


// User function Template for Java

// class Solution {
//     public int longestPalinSubseq(String s) {
//         int n = s.length();
//         int[] prev = new int[n + 1];
//         int[] curr = new int[n + 1];

//         for (int i = 1; i <= n; i++) {
//             for (int j = 1; j <= n; j++) {
//                 if (s.charAt(i - 1) == s.charAt(n - j))
//                     curr[j] = 1 + prev[j - 1];
//                 else
//                     curr[j] = Math.max(prev[j], curr[j - 1]);
//             }
//             int[] temp = prev;
//             prev = curr;
//             curr = temp;
//         }
//         return prev[n];
//     }
// }


class Solution {
    public int longestPalinSubseq(String s) {
        int n = s.length();
        int[][] dp = new int[n][n];
        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s.charAt(i) == s.charAt(j)) 
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                else 
                    dp[i][j] = Math.max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
}
