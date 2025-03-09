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

            System.out.println(obj.countPS(s));

            System.out.println("~");
        }
    }
}
// } Driver Code Ends



class Solution {
    public int countPS(String s) {
        int n = s.length(), res = 0;
        for (int i = 0; i < n; i++) {
            for (int l = i, r = i; l >= 0 && r < n && s.charAt(l) == s.charAt(r); l--, r++) res++;
            for (int l = i, r = i + 1; l >= 0 && r < n && s.charAt(l) == s.charAt(r); l--, r++) res++;
        }
        return res - n;
    }
}

2)
class Solution {
    public int countPS(String s) {
        int n = s.length(), res = 0;
        boolean[][] dp = new boolean[n][n];
        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = true;
            for (int j = i + 1; j < n; j++)
                if (s.charAt(i) == s.charAt(j) && (j - i == 1 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    res++;
                }
        }
        return res;
    }
}
