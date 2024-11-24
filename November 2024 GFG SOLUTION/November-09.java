//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            String arr[] = br.readLine().split(" ");
            int a[] = new int[arr.length];

            for (int i = 0; i < arr.length; i++) {
                a[i] = Integer.parseInt(arr[i]);
            }
            Solution obj = new Solution();
            int f = 0;
            String A = obj.minSum(a);
            System.out.println(A);
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


// User function Template for Java
class Solution {
    public String minSum(int[] arr) {
        Arrays.sort(arr);
        StringBuilder num1 = new StringBuilder();
        StringBuilder num2 = new StringBuilder();
        boolean toggle = true;

        for (int num : arr) {
            if (toggle) {
                if (!(num == 0 && num1.length() == 0)) {
                    num1.append(num);
                }
            } else {
                if (!(num == 0 && num2.length() == 0)) {
                    num2.append(num);
                }
            }
            toggle = !toggle;
        }

        if (num1.length() == 0) num1.append("0");
        if (num2.length() == 0) num2.append("0");

        return findSum(num1.toString(), num2.toString());
    }

    private String findSum(String str1, String str2) {
        int n1 = str1.length(), n2 = str2.length();
        int carry = 0;
        StringBuilder result = new StringBuilder();

        for (int i = 0; i < Math.max(n1, n2) || carry > 0; i++) {
            int digit1 = i < n1 ? str1.charAt(n1 - i - 1) - '0' : 0;
            int digit2 = i < n2 ? str2.charAt(n2 - i - 1) - '0' : 0;
            int sum = digit1 + digit2 + carry;
            result.append(sum % 10);
            carry = sum / 10;
        }

        return result.reverse().toString();
    }
}
