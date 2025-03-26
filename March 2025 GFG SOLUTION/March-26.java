//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class GfG {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        while (t-- > 0) {
            String s = sc.nextLine();
            String line = sc.nextLine();
            String[] dictionary = line.split(" ");

            Solution obj = new Solution();
            if (obj.wordBreak(s, dictionary)) {
                System.out.println("true");
            } else {
                System.out.println("false");
            }
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Solution {
    public boolean wordBreak(String s, String[] d) {
        Set<String> set = new HashSet<>(Arrays.asList(d));
        int n = s.length(), m = 0;
        for (String w : d) m = Math.max(m, w.length());
        boolean[] dp = new boolean[n + 1];
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            if (!dp[i]) continue;
            for (int j = 1; j <= m && i + j <= n; j++)
                if (set.contains(s.substring(i, i + j))) dp[i + j] = true;
        }
        return dp[n];
    }
}
