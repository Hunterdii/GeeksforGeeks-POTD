//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());

        while (tc-- > 0) {

            String[] str = br.readLine().trim().split(" ");
            int[] a = new int[str.length];
            for (int i = 0; i < str.length; i++) {
                a[i] = Integer.parseInt(str[i]);
            }
            String[] nk = br.readLine().trim().split(" ");
            int k = Integer.parseInt(nk[0]);
            Solution sln = new Solution();
            int ans = sln.countFreq(a, k);

            System.out.println(ans);
            System.out.println("~");
        }
    }
}
// } Driver Code Ends



class Solution {
    int countFreq(int[] arr, int target) {
        int low = 0, high = arr.length - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] < target)
                low = mid + 1;
            else
                high = mid;
        }

        if (low >= arr.length || arr[low] != target)
            return 0;

        int first = low;
        high = arr.length - 1;
        while (low < high) {
            int mid = low + (high - low + 1) / 2;
            if (arr[mid] > target)
                high = mid - 1;
            else
                low = mid;
        }

        int last = high;
        return last - first + 1;
    }
}

