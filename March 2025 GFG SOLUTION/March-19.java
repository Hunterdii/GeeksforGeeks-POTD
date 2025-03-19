//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());

        for (int t = 0; t < tc; t++) {
            String[] input = br.readLine().split(" ");
            int arr[] = new int[input.length];

            for (int i = 0; i < arr.length; i++) arr[i] = Integer.parseInt(input[i]);

            // Read the integer k
            int k = Integer.parseInt(br.readLine());

            // Call the solution function
            Solution obj = new Solution();
            System.out.println(obj.maxProfit(arr, k));
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Solution {
    public static int maxProfit(int[] prices, int k) {
        int n = prices.length;
        if (n == 0 || k == 0) return 0;
        if (2 * k >= n) {
            int profit = 0;
            for (int i = 1; i < n; i++)
                profit += Math.max(0, prices[i] - prices[i - 1]);
            return profit;
        }
        int[] dp = new int[2 * k + 1];
        Arrays.fill(dp, Integer.MIN_VALUE);
        dp[0] = 0;
        for (int price : prices)
            for (int j = 1; j <= 2 * k; j++)
                dp[j] = (j % 2 == 1) ? Math.max(dp[j], dp[j - 1] - price) : Math.max(dp[j], dp[j - 1] + price);
        return dp[2 * k];
    }
}
