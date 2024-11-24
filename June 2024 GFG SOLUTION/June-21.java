//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class GFG {
    public static void main(String args[]) throws IOException {

        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));

        Solution ob = new Solution();
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String str = read.readLine().trim();
            String ans = ob.compareFrac(str);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    String compareFrac(String str) {
        int n = str.length();
        int a = 0, b = 0, c = 0, d = 0;
        int i = 0;
        while (i < n && str.charAt(i) != '/') {
            a = a * 10 + str.charAt(i) - '0';
            i++;
        }
        i++;
        while (i < n && str.charAt(i) != ',') {
            b = b * 10 + str.charAt(i) - '0';
            i++;
        }
        i += 2; // Skip ", "
        while (i < n && str.charAt(i) != '/') {
            c = c * 10 + str.charAt(i) - '0';
            i++;
        }
        i++;
        while (i < n) {
            d = d * 10 + str.charAt(i) - '0';
            i++;
        }
        if ((a * d) > (b * c)) {
            return a + "/" + b;
        } else if ((a * d) < (b * c)) {
            return c + "/" + d;
        }
        return "equal";
    }
}

