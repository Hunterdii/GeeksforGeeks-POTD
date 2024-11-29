//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            String a, b;
            a = sc.next();
            b = sc.next();
            Solution ob = new Solution();
            System.out.println(ob.addBinary(a, b));

            System.out.println("~");
        }
    }
}
// } Driver Code Ends


// User function Template for Java
class Solution {
    public String addBinary(String s1, String s2) {
        int n1 = s1.length(), n2 = s2.length();
        StringBuilder result = new StringBuilder();
        
        int carry = 0;
        int i = n1 - 1, j = n2 - 1;
        
        while (i >= 0 || j >= 0 || carry == 1) {
            int sum = carry;
            
            if (i >= 0) sum += s1.charAt(i--) - '0';  
            if (j >= 0) sum += s2.charAt(j--) - '0';  
            
            result.append(sum % 2);  
            carry = sum / 2;         
        }
        
        result.reverse();
        
        while (result.length() > 1 && result.charAt(0) == '0') {
            result.deleteCharAt(0);
        }
        
        return result.toString();
    }
}
