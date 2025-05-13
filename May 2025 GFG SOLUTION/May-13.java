//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int r = sc.nextInt();
            Solution ob = new Solution();
            System.out.println(ob.nCr(n, r));
            System.out.println("~");
        }

        sc.close();
    }
}
// } Driver Code Ends


class Solution {
    static final int MOD = (int)1e9+7;
    long modexp(long x, long y) {
        long res = 1;
        while (y > 0) {
            if ((y & 1) == 1) res = res * x % MOD;
            x = x * x % MOD;
            y >>= 1;
        }
        return res;
    }
    public int nCr(int n, int r) {
        if (r > n) return 0;
        long[] fact = new long[n+1], inv = new long[n+1];
        fact[0] = 1;
        for (int i = 1; i <= n; ++i)
            fact[i] = fact[i-1] * i % MOD;
        inv[n] = modexp(fact[n], MOD-2);
        for (int i = n; i > 0; --i)
            inv[i-1] = inv[i] * i % MOD;
        return (int)(fact[n] * inv[r] % MOD * inv[n-r] % MOD);
    }
}


// 2) Solution @itsjomon

class Solution {
    public int nCr(int n, int r) {
        if (r > n) { // valid for n ≤ 100 as per problem constraints
            return 0;
        }
        long sum = 1;
        for (int i = 1; i <= r; i++) {
            sum = sum * (n - r + i) / i;
        }
        return (int)sum;
    }
}
