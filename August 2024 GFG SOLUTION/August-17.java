//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0) {
            int n = sc.nextInt();
            int[] array = new int[n];
            for (int i = 0; i < n; i++) {
                array[i] = sc.nextInt();
            }
            Solution ob = new Solution();
            long[] ans = new long[n];
            ans = ob.productExceptSelf(array);

            for (int i = 0; i < n; i++) {
                System.out.print(ans[i] + " ");
            }
            System.out.println();
            t--;
        }
    }
}

// } Driver Code Ends


// User function Template for Java
class Solution {
    public long[] productExceptSelf(int[] nums) {
        int n = nums.length;
        long[] leftProduct = new long[n];
        long[] result = new long[n];
        
        leftProduct[0] = 1;
        for (int i = 1; i < n; i++) {
            leftProduct[i] = leftProduct[i - 1] * nums[i - 1];
        }

        long rightProductAcc = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] = leftProduct[i] * rightProductAcc;
            rightProductAcc *= nums[i];
        }

        return result;
    }
}
