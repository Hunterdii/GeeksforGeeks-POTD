//{ Driver Code Starts
// Initial Template for Java

// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {

        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));

        Solution ob = new Solution();
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String input_line[] = read.readLine().trim().split("\\s+");
            int n = Integer.parseInt(input_line[0]);
            String input_line1[] = read.readLine().trim().split("\\s+");
            int[][] a = new int[n][n];
            int c = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    a[i][j] = Integer.parseInt(input_line1[c]);
                    c++;
                }
            }
            String ans = ob.pattern(a);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    public boolean isPalindrome(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n / 2; ++i) {
            if (arr[i] != arr[n - 1 - i]) {
                return false;
            }
        }
        return true;
    }

    public String pattern(int[][] arr) {
        int n = arr.length;

        for (int i = 0; i < n; ++i) {
            if (isPalindrome(arr[i])) {
                return i + " R";
            }
        }

        for (int j = 0; j < n; ++j) {
            int[] col = new int[n];
            for (int i = 0; i < n; ++i) {
                col[i] = arr[i][j];
            }
            if (isPalindrome(col)) {
                return j + " C";
            }
        }

        return "-1";
    }
}
