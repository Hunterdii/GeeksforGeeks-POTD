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
                    String S = sc.next();
                    int R = sc.nextInt();
                    int N = sc.nextInt();
                    Solution obj = new Solution();
                    System.out.println(obj.nthCharacter(S,R,N));
                }
                
        }
}

// } Driver Code Ends


//User function Template for Java

class Solution {
    char nthCharacter(String s, int r, int n) {
        n += 1;
        StringBuilder f = new StringBuilder();
        int it = 0;
        int l = 0;

        while (l < n) {
            it += 1;
            l = it * (int)Math.pow(2, r);
        }

        int p = (int)Math.pow(2, r);

        n -= 1;
        n %= p;

        if (it == 0) {
            it += 1;
        }

        f.append(s.charAt(it - 1));

        for (int i = 0; i < r; i++) {
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < f.length(); j++) {
                if (f.charAt(j) == '1') {
                    sb.append("10");
                } else {
                    sb.append("01");
                }
            }
            f = sb;
        }

        return f.charAt(n);
    }

}
