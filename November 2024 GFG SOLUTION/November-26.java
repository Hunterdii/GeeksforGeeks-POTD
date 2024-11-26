//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Sorting {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int g = 0; g < t; g++) {
            String[] str = (br.readLine()).trim().split(" ");
            int arr[] = new int[str.length];
            for (int i = 0; i < str.length; i++) arr[i] = Integer.parseInt(str[i]);
            System.out.println(new Solution().circularSubarraySum(arr));
            // System.out.println("~");
        }
    }
}
// } Driver Code Ends

class Solution {
    public int circularSubarraySum(int arr[]) {
        int totalSum = 0, maxSum = Integer.MIN_VALUE, minSum = Integer.MAX_VALUE;
        int currMax = 0, currMin = 0;
        boolean allNegative = true;

        for (int num : arr) {
            totalSum += num;

            currMax = Math.max(num, currMax + num);
            maxSum = Math.max(maxSum, currMax);

            currMin = Math.min(num, currMin + num);
            minSum = Math.min(minSum, currMin);

            if (num > 0) allNegative = false;
        }

        if (allNegative) return maxSum;

        return Math.max(maxSum, totalSum - minSum);
    }
}
