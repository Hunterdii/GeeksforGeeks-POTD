//{ Driver Code Starts
import java.util.*;

class GFG {
    public static void main(String args[]) throws Exception {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while (T > 0) {
            int N = sc.nextInt();
            int k = sc.nextInt();
            int ar[] = new int[N];
            //	int count = 0;
            for (int i = 0; i < N; i++) ar[i] = sc.nextInt();

            System.out.println(new Solution().max_Books(ar, N, k));
            T--;
        }
    }
}
// } Driver Code Ends



class Solution {
    long max_Books(int arr[], int n, int k) {
        long max_sum = 0, current_sum = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] <= k) {
                current_sum += arr[i];
                max_sum = Math.max(max_sum, current_sum);
            } else {
                current_sum = 0;
            }
        }
        return max_sum;
    }
}
