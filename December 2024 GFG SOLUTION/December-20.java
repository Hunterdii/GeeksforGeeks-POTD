//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int r = sc.nextInt();
            int c = sc.nextInt();

            int matrix[][] = new int[r][c];

            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) matrix[i][j] = sc.nextInt();
            }
            Solution ob = new Solution();
            ArrayList<Integer> ans = ob.spirallyTraverse(matrix);
            for (Integer val : ans) System.out.print(val + " ");
            System.out.println();

            System.out.println("~");
        }
    }
}
// } Driver Code Ends

class Solution {
    public ArrayList<Integer> spirallyTraverse(int[][] mat) {
        ArrayList<Integer> result = new ArrayList<>();
        int top = 0, left = 0, bottom = mat.length - 1, right = mat[0].length - 1;

        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) result.add(mat[top][i]);
            top++;
            for (int i = top; i <= bottom; i++) result.add(mat[i][right]);
            right--;
            if (top <= bottom)
                for (int i = right; i >= left; i--) result.add(mat[bottom][i]);
            bottom--;
            if (left <= right)
                for (int i = bottom; i >= top; i--) result.add(mat[i][left]);
            left++;
        }
        return result;
    }
}
