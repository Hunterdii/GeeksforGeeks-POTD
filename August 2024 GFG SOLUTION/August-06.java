//{ Driver Code Starts
// Initial Template for Java

// Initial Template for Java

import java.io.*;
import java.util.*;

public class validip {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            String s = sc.next();
            Solution obj = new Solution();

            if (obj.isValid(s))
                System.out.println("true");
            else
                System.out.println("false");
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {

    public boolean isValid(String str) {
        int n = str.length();
        int segments = 0;
        int num = 0;
        int length = 0;

        for (int i = 0; i < n; ++i) {
            if (str.charAt(i) == '.') {
                if (length == 0 || length > 3 || num > 255)
                    return false;
                segments++;
                num = 0;
                length = 0;
            } else if (Character.isDigit(str.charAt(i))) {
                if (length == 0 && str.charAt(i) == '0' && (i + 1 < n && str.charAt(i + 1) != '.'))
                    return false;
                num = num * 10 + (str.charAt(i) - '0');
                length++;
            } else {
                return false;
            }
        }

        if (length == 0 || length > 3 || num > 255)
            return false;
        segments++;

        return segments == 4;
    }
}
