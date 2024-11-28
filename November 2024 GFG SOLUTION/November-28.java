//{ Driver Code Starts
// Initial template for JAVA

import java.util.Scanner;

class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        while (t > 0) {
            String str = sc.nextLine();

            Solution obj = new Solution();
            int num = obj.myAtoi(str);
            System.out.println(num);
            System.out.println("~");
            t--;
        }
    }
}
// } Driver Code Ends

class Solution {
    public int myAtoi(String s) {
        int idx = 0, sign = 1;
        long res = 0;

        while (idx < s.length() && s.charAt(idx) == ' ') idx++;

        if (idx < s.length() && (s.charAt(idx) == '-' || s.charAt(idx) == '+')) {
            sign = (s.charAt(idx++) == '-') ? -1 : 1;
        }

        while (idx < s.length() && s.charAt(idx) >= '0' && s.charAt(idx) <= '9') {
            res = res * 10 + (s.charAt(idx++) - '0');

            if (res * sign > Integer.MAX_VALUE) return Integer.MAX_VALUE;
            if (res * sign < Integer.MIN_VALUE) return Integer.MIN_VALUE;
        }

        return (int)(res * sign);
    }
}
