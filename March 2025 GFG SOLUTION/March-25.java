//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;
import java.util.stream.*;

class GFG {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String s = br.readLine();
            Solution obj = new Solution();
            System.out.println(obj.countWays(s));
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Solution {
    static int countWays(String s) {
        int n = s.length();
        int[][] T = new int[n][n], F = new int[n][n];
        for (int i = 0; i < n; i += 2) T[i][i] = s.charAt(i) == 'T' ? 1 : 0;
        for (int i = 0; i < n; i += 2) F[i][i] = s.charAt(i) == 'F' ? 1 : 0;
        for (int l = 2; l < n; l += 2)
            for (int i = 0; i < n - l; i += 2)
                for (int k = i + 1, j = i + l; k < j; k += 2) {
                    int lt = T[i][k - 1], lf = F[i][k - 1], rt = T[k + 1][j], rf = F[k + 1][j];
                    if (s.charAt(k) == '&') {
                        T[i][j] += lt * rt;
                        F[i][j] += lt * rf + lf * rt + lf * rf;
                    } else if (s.charAt(k) == '|') {
                        T[i][j] += lt * rt + lt * rf + lf * rt;
                        F[i][j] += lf * rf;
                    } else {
                        T[i][j] += lt * rf + lf * rt;
                        F[i][j] += lt * rt + lf * rf;
                    }
                }
        return T[0][n - 1];
    }
}
