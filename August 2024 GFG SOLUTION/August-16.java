//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;
import java.lang.*;

class Driver
{
    public static void main(String args[])throws IOException
    {
        //reading input using BufferedReader class
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        
        //reading total testcases
        int t = Integer.parseInt(read.readLine());
        
        while(t-- > 0)
        {
            //reading length of line segment
            int n = Integer.parseInt(read.readLine().trim());
            
            
            //reading 3 segment lengths
            String str[] = read.readLine().trim().split(" ");
            
            int x = Integer.parseInt(str[0]);
            int y = Integer.parseInt(str[1]);
            int z = Integer.parseInt(str[2]);
            
            
            //calling method maximizeCuts() of class Solution()
            //and printinting the result
            System.out.println(new Solution().maximizeCuts(n, x, y, z));
        }
    }
}

// } Driver Code Ends

//User function Template for Java
class Solution {
    public int maximizeCuts(int n, int x, int y, int z) {
        int[] dp = new int[n + 1];
        Arrays.fill(dp, -1);
        dp[0] = 0;

        int[] cuts = {x, y, z};

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 3; j++) {
                if (i >= cuts[j] && dp[i - cuts[j]] != -1) {
                    dp[i] = Math.max(dp[i], dp[i - cuts[j]] + 1);
                }
            }
        }

        return dp[n] == -1 ? 0 : dp[n];
    }
}

