//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0) {
            int N = sc.nextInt();
            int M[][] = new int[N][N];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    M[i][j] = sc.nextInt();
                }
            }
            System.out.println(new Solution().celebrity(M));
            t--;
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    public int celebrity(int[][] mat) {
        int n = mat.length;
        int potentialCelebrity = 0;
        for (int i = 1; i < n; ++i) {
            if (mat[potentialCelebrity][i] == 1) {
                potentialCelebrity = i;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i != potentialCelebrity && (mat[potentialCelebrity][i] == 1 || mat[i][potentialCelebrity] == 0)) {
                return -1;
            }
        }

        return potentialCelebrity;
    }
}
