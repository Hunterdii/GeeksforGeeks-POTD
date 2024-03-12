//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String S[] = read.readLine().split(" ");
            
            long a = Long.parseLong(S[0]);
            long b = Long.parseLong(S[1]);
            long c = Long.parseLong(S[2]);
            long n = Long.parseLong(S[3]);
            long m = Long.parseLong(S[4]);

            Solution ob = new Solution();
            System.out.println(ob.genFibNum(a,b,c,n,m));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution {
    public long[][] multiply(long[][] A, long[][] B, long m) {
        int size = A.length;
        long[][] result = new long[size][size];
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                for (int k = 0; k < size; ++k) {
                    result[i][j] += (A[i][k] % m) * (B[k][j] % m);
                    result[i][j] %= m;
                }
            }
        }
        return result;
    }

    public long genFibNum(long a, long b, long c, long n, long m) {
        if (n <= 2)
            return 1L % m;
        long[][] mat = {{a, b, 1}, {1, 0, 0}, {0, 0, 1}};
        long[][] res = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        n -= 2;
        while (n > 0) {
            if ((n & 1) == 1)
                res = multiply(res, mat, m);
            mat = multiply(mat, mat, m);
            n >>= 1;
        }
        return (res[0][0] + res[0][1] + c * res[0][2]) % m;
    }

};
