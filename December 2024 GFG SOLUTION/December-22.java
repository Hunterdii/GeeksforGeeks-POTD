//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class gfg {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int m = sc.nextInt();

            int mat[][] = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) mat[i][j] = sc.nextInt();
            }

            int x = sc.nextInt();

            if (new Solution().matSearch(mat, x))
                System.out.println("true");
            else
                System.out.println("false");

            System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Solution {
    public boolean matSearch(int[][] mat, int x) {
        int r = 0, c = mat[0].length - 1;
        while (r < mat.length && c >= 0) {
            if (mat[r][c] == x) return true;
            else if (mat[r][c] > x) c--;
            else r++;
        }
        return false;
    }
}

2)
class Solution {
    public static boolean matSearch(int[][] mat, int x) {
        int r = 0, c = mat[0].length - 1;  // Start from the top-right corner
        while (r < mat.length && c >= 0) {
            int current = mat[r][c];
            if (current == x) {
                return true;  // Element found
            } else if (current > x) {
                c--;  // Move left if current element is greater
            } else {
                r++;  // Move down if current element is smaller
            }
        }
        return false;  // Element not found
    }
}

