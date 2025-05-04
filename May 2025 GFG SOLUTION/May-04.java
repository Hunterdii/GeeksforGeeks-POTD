//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            String str = br.readLine();

            Solution obj = new Solution();
            System.out.println(obj.findSubString(str));

            System.out.println("~");
        }
    }
}

// } Driver Code Ends


class Solution {
    public int findSubString(String s) {
        Set<Character> all = new HashSet<>();
        for (char c : s.toCharArray()) all.add(c);
        int n = s.length(), i = 0, j = 0, d = all.size(), c = 0, res = n;
        int[] freq = new int[256];
        while (j < n) {
            if (++freq[s.charAt(j++)] == 1) c++;
            while (c == d) {
                res = Math.min(res, j - i);
                if (--freq[s.charAt(i++)] == 0) c--;
            }
        }
        return res;
    }
}
