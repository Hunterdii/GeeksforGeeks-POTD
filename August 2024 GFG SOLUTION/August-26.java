//{ Driver Code Starts
import java.util.*;

class WildcardPattern {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        while (t > 0) {
            String pat = sc.nextLine();
            String text = sc.nextLine();
            Solution g = new Solution();
            System.out.println(g.wildCard(pat, text));
            t--;
        }
    }
}
// } Driver Code Ends

class Solution {
    public int wildCard(String pattern, String str) {
        int m = str.length();
        int n = pattern.length();
        int[] dp = new int[n + 1];
        dp[0] = 1;

        for (int j = 1; j <= n; j++) {
            if (pattern.charAt(j - 1) == '*') {
                dp[j] = dp[j - 1];
            }
        }

        for (int i = 1; i <= m; i++) {
            int[] newDp = new int[n + 1];
            for (int j = 1; j <= n; j++) {
                if (pattern.charAt(j - 1) == '?' || pattern.charAt(j - 1) == str.charAt(i - 1)) {
                    newDp[j] = dp[j - 1];
                } else if (pattern.charAt(j - 1) == '*') {
                    newDp[j] = dp[j] | newDp[j - 1];
                }
            }
            dp = newDp;
        }

        return dp[n];
    }
}
