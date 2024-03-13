//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            int n = Integer.parseInt(br.readLine().trim());
            int[][] mat = new int[n][n];
            String[] S = br.readLine().trim().split(" ");
            int i = 0;
            int j = 0;
            for(int k = 0; k < S.length; k++){
                mat[i][j] = Integer.parseInt(S[k]);
                j++;
                if(j == n){
                    i++;
                    j = 0;
                }
            }
            Solution obj = new Solution();
            int[] ans = obj.matrixDiagonally(mat);
            for(int it = 0; it < ans.length; it++){
                System.out.print(ans[it] + " ");
            }
            System.out.println();
        }
    }
}

// } Driver Code Ends


class Solution {
    public int[] matrixDiagonally(int[][] mat) {
        Map<Integer, List<Integer>> diagonalMap = new HashMap<>();
        int n = mat.length;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int diagonalIndex = i + j;
                if (!diagonalMap.containsKey(diagonalIndex)) {
                    diagonalMap.put(diagonalIndex, new ArrayList<>());
                }
                diagonalMap.get(diagonalIndex).add(mat[i][j]);
            }
        }

        List<Integer> diagonalOrder = new ArrayList<>();
        for (int key : diagonalMap.keySet()) {
            if (key % 2 == 0) {
                Collections.reverse(diagonalMap.get(key));
            }
            diagonalOrder.addAll(diagonalMap.get(key));
        }

        int[] diagonalArray = new int[diagonalOrder.size()];
        for (int i = 0; i < diagonalOrder.size(); i++) {
            diagonalArray[i] = diagonalOrder.get(i);
        }

        return diagonalArray;
    }


}
