//{ Driver Code Starts
import java.util.*;

class Check_IsToepliz {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T > 0) {
            int N = sc.nextInt();
            int M = sc.nextInt();
            int arr[][] = new int[N][M];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) arr[i][j] = sc.nextInt();
            }

            GfG g = new GfG();
            boolean b = g.isToepliz(arr);
            if (N == 2 && M == 4) {
                System.out.println(0);
            } else {
                if (b == true)
                    System.out.println("true");
                else
                    System.out.println("false");
            }

            T--;
        }
    }
}
// } Driver Code Ends


class GfG {
    /*You are required to complete this method*/
    boolean isToepliz(int mat[][]) {
        Map<Integer, Integer> map = new HashMap<>();
        int m = mat.length, n = mat[0].length;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int diff = i - j;
                if (map.containsKey(diff)) {
                    if (!map.get(diff).equals(mat[i][j]))
                        return false;
                } else {
                    map.put(diff, mat[i][j]);
                }
            }
        }
        
        return true;
    }
}
