//{ Driver Code Starts
// Initial Template for Java

import java.math.*;
import java.util.*;

class Multiply {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            String a = sc.next();
            String b = sc.next();
            Solution g = new Solution();
            System.out.println(g.multiplyStrings(a, b));

            System.out.println("~");
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    public String multiplyStrings(String s1, String s2) {
        int sign = 1;
        if (s1.charAt(0) == '-') { sign = -sign; s1 = s1.substring(1); }
        if (s2.charAt(0) == '-') { sign = -sign; s2 = s2.substring(1); }
        if (s1.equals("0") || s2.equals("0")) return "0";
        int n = s1.length(), m = s2.length();
        int[] res = new int[n + m];
        for (int i = n - 1; i >= 0; i--)
            for (int j = m - 1; j >= 0; j--)
                res[i + j + 1] += (s1.charAt(i) - '0') * (s2.charAt(j) - '0');
        for (int i = n + m - 1; i > 0; i--) {
            res[i - 1] += res[i] / 10;
            res[i] %= 10;
        }
        int i = 0;
        while (i < res.length && res[i] == 0) i++;
        StringBuilder ans = new StringBuilder();
        for (; i < res.length; i++) ans.append(res[i]);
        return sign == -1 ? "-" + ans.toString() : ans.toString();
    }
}
