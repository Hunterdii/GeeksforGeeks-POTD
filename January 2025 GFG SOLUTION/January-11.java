//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.HashMap;
import java.util.HashSet;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String s = read.readLine();
            Solution ob = new Solution();
            System.out.println(ob.longestUniqueSubstr(s));
            System.out.println("~");
        }
    }
}

// } Driver Code Ends

class Solution {
    public int longestUniqueSubstr(String s) {
        int[] lastSeen = new int[128];
        int maxLength = 0, start = 0;
        for (int end = 0; end < s.length(); end++) {
            start = Math.max(start, lastSeen[s.charAt(end)]);
            lastSeen[s.charAt(end)] = end + 1;
            maxLength = Math.max(maxLength, end - start + 1);
        }
        return maxLength;
    }
}
