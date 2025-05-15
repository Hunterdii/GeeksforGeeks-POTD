//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String s = read.readLine();

            Solution ob = new Solution();
            int result = ob.countSubstring(s);

            System.out.println(result);
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Solution {
    public int countSubstring(String s) {
        int[] cnt = new int[256];
        long ans = 0;
        for (char c : s.toCharArray()) cnt[c]++;
        for (int x : cnt) ans += (long)x * (x + 1) / 2;
        return (int)ans;
    }
}
