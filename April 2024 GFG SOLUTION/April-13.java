//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            Long X = Long.parseLong(read.readLine());

            Solution ob = new Solution();
            System.out.println(ob.reversedBits(X));
        }
    }
}
// } Driver Code Ends


// User function Template for Java
class Solution {
    public long reversedBits(long x) {
        long ans = 0;
        for (int i = 0; i < 32; ++i) {
            ans = (ans << 1) | (x & 1); // Shift ans left by 1 and OR it with the least significant bit of x
            x >>= 1; // Shift x right by 1 to process the next bit
        }
        return ans;
    }
};
