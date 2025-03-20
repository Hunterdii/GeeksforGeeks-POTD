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
            System.out.println(new Solution().maxProfit(arr));
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Solution {
    public static int maxProfit(int[] a) {
        int b1 = Integer.MAX_VALUE, s1 = 0, b2 = Integer.MAX_VALUE, s2 = 0;
        for (int p : a) {
            b1 = Math.min(b1, p);
            s1 = Math.max(s1, p - b1);
            b2 = Math.min(b2, p - s1);
            s2 = Math.max(s2, p - b2);
        }
        return s2;
    }
}
