//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
class GfG
{
    public static void main(String args[])
        {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0)
                {
                    int n = sc.nextInt();
                    Solution ob = new Solution();
                    System.out.println(ob.padovanSequence(n));
                }
        }
}    
// } Driver Code Ends


//User function Template for Java

class Solution {
    public int padovanSequence(int n) {
        final int MOD = 1000000007;
        if (n == 0 || n == 1 || n == 2)
            return 1;

        int[] p = {1, 1, 1};
        for (int i = 3; i <= n; ++i) {
            int p_next = (p[0] + p[1]) % MOD;
            p[0] = p[1];
            p[1] = p[2];
            p[2] = p_next;
        }
        return p[2];
    }
}

