//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            int N = Integer.parseInt(read.readLine());
            String S = read.readLine();

            Solution ob = new Solution();
            System.out.println(ob.longestSubstring(S, N));
        }
    }
}

// } Driver Code Ends


//User function Template for Java
class Solution {
    static String longestSubstring(String s, int n) {
        int maxLen = 0;
        String ans = "-1";
        int i = 0, j = 0;

        while (i < n && j < n) {
            String subString = s.substring(i, j + 1);

            if (s.indexOf(subString, j + 1) != -1) {
                int len = subString.length();
                if (len > maxLen) {
                    maxLen = len;
                    ans = subString;
                }
            } else {
                i++;
            }
            j++;
        }
        return ans;
    }

};
