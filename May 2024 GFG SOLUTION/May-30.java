//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {

            String s1;
            s1 = br.readLine();

            String s2;
            s2 = br.readLine();

            Solution obj = new Solution();
            int res = obj.countWays(s1, s2);

            System.out.println(res);
        }
    }
}

// } Driver Code Ends

class Solution {
    public static int countWays(String s1, String s2) {
        int n = s1.length(), m = s2.length();
        int[][] memo = new int[n + 1][m + 1];
        for (int[] row : memo) {
            Arrays.fill(row, -1);
        }
        int mod = 1_000_000_007;

        return dp(n, m, s1, s2, memo, mod);
    }

    private static int dp(int i, int j, String s1, String s2, int[][] memo, int mod) {
        if (j == 0) return 1; 
        if (i == 0) return 0; 
        if (memo[i][j] != -1) return memo[i][j];

        if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
            memo[i][j] = (dp(i - 1, j - 1, s1, s2, memo, mod) + dp(i - 1, j, s1, s2, memo, mod)) % mod;
        } else {
            memo[i][j] = dp(i - 1, j, s1, s2, memo, mod) % mod;
        }

        return memo[i][j];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String s1 = br.readLine();
            String s2 = br.readLine();
            Solution obj = new Solution();
            int res = obj.countWays(s1, s2);
            System.out.println(res);
        }
    }
}

