//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Main {
    // Driver code
    public static void main(String[] args) throws Exception {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            Solution obj = new Solution();
            int ans[] = obj.Series(n);
            for (int i : ans) {
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }
}
// } Driver Code Ends


class Solution {
    int[] Series(int n) {
        int MOD = 1000000007;
        int[] ans = new int[n + 1];
        if (n == 0) return ans; 
        
        int prev = 0, cur = 1;
        ans[0] = prev;
        ans[1] = cur;
        
        for (int i = 2; i <= n; ++i) {
            int next = (prev + cur) % MOD;
            ans[i] = next;
            prev = cur;
            cur = next;
        }
        
        return ans;
    }

}
