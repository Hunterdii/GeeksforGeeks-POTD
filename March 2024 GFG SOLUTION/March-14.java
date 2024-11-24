//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            int N = Integer.parseInt(read.readLine());
            char A[][] = new char[N][N];
            for (int i = 0; i < N; i++) {
                String S[] = read.readLine().trim().split(" ");
                for (int j = 0; j < N; j++) A[i][j] = S[j].charAt(0);
            }
            Solution ob = new Solution();
            System.out.println(ob.largestSubsquare(N, A));
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    int largestSubsquare(int n, char a[][]) {
        int[][] v1 = new int[n][n];
        int[][] v2 = new int[n][n];

        // col
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (a[i][j] == 'O') {
                    sum = 0;
                    v1[i][j] = 0;
                } else {
                    sum++;
                    v1[i][j] = sum;
                }
            }
        }

        // rows
        int maxi = 10002;
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int i = n - 1; i >= 0; i--) {
                if (a[i][j] == 'O')
                    sum = 0;
                else {
                    sum++;
                    v2[i][j] = sum;
                }
            }
        }

        // finding max submatrix
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 'O')
                    continue;

                int size = Math.min(v1[i][j], v2[i][j]);

                while (size > ans) {
                    if (v1[i + size - 1][j] >= size && v2[i][j + size - 1] >= size)
                        ans = size;

                    size--;
                }
            }
        }
        return ans;
    }

};
