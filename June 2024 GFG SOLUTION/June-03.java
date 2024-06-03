//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            int N = Integer.parseInt(read.readLine());

            Solution ob = new Solution();
            System.out.println(ob.numberOfConsecutiveOnes(N));
        }
    }
}
// } Driver Code Ends

class Solution {
    static int numberOfConsecutiveOnes(int n) {
        final long MOD = 1_000_000_007;
        if (n == 1 || n == 2) {
            return 1;
        }
        long a = 1, b = 1;
        long res = 1;
        for (int i = 3; i <= n; i++) {
            long c = (a + b) % MOD; 
            a = b;
            b = c;
            res = (res * 2 + a) % MOD;
        }
        return (int) res;
    }
}

