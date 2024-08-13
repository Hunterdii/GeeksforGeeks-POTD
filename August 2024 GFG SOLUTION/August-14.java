//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String S1 = read.readLine().trim();
            String S2 = read.readLine().trim();

            Solution ob = new Solution();
            System.out.println(ob.longestCommonSubstr(S1, S2));
        }
    }
}
// } Driver Code Ends


// User function Template for Java
class Solution {
    public int longestCommonSubstr(String str1, String str2) {
        int n = str1.length(), m = str2.length();
        int res = 0;

        int[] prev = new int[m + 1];
        int[] curr = new int[m + 1];

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    curr[j] = 1 + prev[j - 1];
                    res = Math.max(res, curr[j]);
                } else {
                    curr[j] = 0;
                }
            }
            prev = curr.clone(); 
        }
        return res;
    }
}
