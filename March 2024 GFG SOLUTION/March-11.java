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
            String input[] = read.readLine().split(" ");
            
            int n = Integer.parseInt(input[0]);
            int x = Integer.parseInt(input[1]);
            
            int mat1[][] = new int[n][n];
            
            for(int i = 0;i<n;i++){
                input = read.readLine().split(" ");
                for(int j = 0;j<n;j++){
                    mat1[i][j] = Integer.parseInt(input[j]);
                }
            }
            
            int mat2[][] = new int[n][n];
            
            for(int i = 0;i<n;i++){
                input = read.readLine().split(" ");
                for(int j = 0;j<n;j++){
                    mat2[i][j] = Integer.parseInt(input[j]);
                }
            }
            
        
            
            Solution ob = new Solution();
            System.out.println(ob.countPairs(mat1,mat2,n,x));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution {
  int countPairs(int[][] mat1, int[][] mat2, int n, int x) {
    int count = 0;
    int r1 = 0, c1 = 0;
    int r2 = n - 1, c2 = n - 1;

    while ((r1 < n) && (r2 >= 0)) {
      int val = mat1[r1][c1] + mat2[r2][c2];

      if (val == x) {
        count++;
        c1++;
        c2--;
      } else if (val < x) {
        c1++;
      } else {
        c2--;
      }

      // Handle boundary conditions within the loop
      if (c1 == n) {
        c1 = 0;
        r1++;
      }
      if (c2 == -1) {
        c2 = n - 1;
        r2--;
      }
    }

    return count;
  }

}
