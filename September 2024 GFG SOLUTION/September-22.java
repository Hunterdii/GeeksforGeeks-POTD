//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {

            String s = read.readLine();
            Solution ob = new Solution();
            System.out.println(ob.lps(s));
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    public int lps(String str) {
        int n = str.length();
        if (n == 0) return 0;

        int[] lpsArr = new int[n];
        int j = 0;  

        for (int i = 1; i < n; i++) {
            while (j > 0 && str.charAt(i) != str.charAt(j)) {
                j = lpsArr[j - 1];
            }
            if (str.charAt(i) == str.charAt(j)) {
                j++;
            }
            lpsArr[i] = j;
        }

        return lpsArr[n - 1];
    }
}
