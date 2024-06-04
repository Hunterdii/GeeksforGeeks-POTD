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
            Solution ob = new Solution();
            System.out.println(ob.binaryNextNumber(s));
        }
    }
}
// } Driver Code Ends


// User function Template for Java
class Solution {
    String binaryNextNumber(String s) {
        s = s.replaceFirst("^0+(?!$)", "");
        if (s.isEmpty()) s = "0";
        
        int n = s.length();
        boolean carry = true;
        char[] charArray = s.toCharArray();
        for (int i = n - 1; i >= 0 && carry; --i) {
            if (charArray[i] == '0') {
                charArray[i] = '1';
                carry = false;
            } else {
                charArray[i] = '0';
            }
        }
        if (carry) {
            s = '1' + new String(charArray);
        } else {
            s = new String(charArray);
        }
        
        return s;
    }
}
