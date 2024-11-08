//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String A = read.readLine();
            String B = read.readLine();

            Solution ob = new Solution();
            out.println(ob.minRepeats(A, B));
        }
        out.close();
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {

    static void computeLPSArray(String s, int[] lps) {
        int len = 0, idx = 1;

        lps[0] = 0;

        while (idx < s.length()) {
            if (s.charAt(idx) == s.charAt(len)) {
                len++;
                lps[idx] = len;
                idx++;
            } else {

                if (len == 0) {
                    lps[idx] = 0;
                    idx++;
                } else {

                    len = lps[len - 1];
                }
            }
        }
    }

    static boolean KMPSearch(String txt, String pat, int[] lps, int rep) {
        int n = txt.length(), m = pat.length();
        int i = 0, j = 0;

        while (i < n * rep) {

            if (txt.charAt(i % n) == pat.charAt(j)) {
                i++;
                j++;

                if (j == m) {
                    return true;
                }
            } else {

                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
        return false;
    }

    static int minRepeats(String s1, String s2) {

        int n = s1.length();
        int m = s2.length();

        int[] lps = new int[m];
        computeLPSArray(s2, lps);

        int x = (m + n - 1) / n;

        if (KMPSearch(s1, s2, lps, x)) return x;

        if (KMPSearch(s1, s2, lps, x + 1)) return x + 1;

        return -1;
    }
};
