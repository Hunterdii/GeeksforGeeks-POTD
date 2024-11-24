//{ Driver Code Starts
import java.util.*;
import java.io.*;
import java.lang.*;

class OptimalStrategy
{
    public static void main (String[] args) {
        
        //taking input using Scanner class
        Scanner sc = new Scanner(System.in);
        
        //taking total number of testcases
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            //taking number of elements
            int n = sc.nextInt();
            int arr[] = new int[n];
            
            //inserting the elements
            for(int i = 0; i < n; i++)
                arr[i] = sc.nextInt();
                
           //calling the countMaximum() method of class solve
           System.out.println(new solve().countMaximum(n, arr)); 
        }
    }
    
    
}
// } Driver Code Ends


class solve {
    // Function to find the maximum possible amount of money we can win.
    static long countMaximum(int n, int arr[]) {
        long[][] dp = new long[n][n];

        for (int gap = 0; gap < n; ++gap) {
            for (int i = 0, j = gap; j < n; ++i, ++j) {
                long x = (i + 2 <= j) ? dp[i + 2][j] : 0;
                long y = (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0;
                long z = (i <= j - 2) ? dp[i][j - 2] : 0;
                dp[i][j] = Math.max(arr[i] + Math.min(x, y), arr[j] + Math.min(y, z));
            }
        }

        return dp[0][n - 1];
    }
}

