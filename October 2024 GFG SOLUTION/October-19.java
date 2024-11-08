//{ Driver Code Starts
// Initial Template for Java

// Initial Template for Java

/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;


// } Driver Code Ends
// User function Template for Java
class Solution {
    String roundToNearest(String str) {
        int n = str.length();
        if (n == 0) return str;  

        int lastDigit = str.charAt(n - 1) - '0';  

        if (lastDigit <= 5) {
            str = str.substring(0, n - 1) + '0';  
        } else {
            str = str.substring(0, n - 1) + '0';  
            int i = n - 2;

            while (i >= 0) {
                if (str.charAt(i) != '9') {
                    str = str.substring(0, i) + (char)(str.charAt(i) + 1) + str.substring(i + 1);  
                    break;
                }
                str = str.substring(0, i) + '0' + str.substring(i + 1);  
                i--;
            }
            if (i < 0) {
                str = '1' + str;  
            }
        }
        return str;
    }
}
//{ Driver Code Starts.

// Driver class
class Array {

    // Driver code
    public static void main(String[] args) throws IOException {
        // Taking input using buffered reader
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int testcases = Integer.parseInt(br.readLine());

        // looping through all testcases
        while (testcases-- > 0) {

            String str = br.readLine().trim();

            Solution obj = new Solution();

            String res = obj.roundToNearest(str);

            System.out.println(res);
        }
    }
}

// } Driver Code Ends
