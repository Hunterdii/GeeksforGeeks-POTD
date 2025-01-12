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
            System.out.println(new Solution().maxWater(arr));
            System.out.println("~");
        }
    }
}
// } Driver Code Ends

class Solution {
    public int maxWater(int[] arr) {
        int l = 0, r = arr.length - 1, res = 0, lMax = 0, rMax = 0;
        while (l < r) {
            if (arr[l] < arr[r]) {
                lMax = lMax > arr[l] ? lMax : arr[l];
                res += lMax - arr[l++];
            } else {
                rMax = rMax > arr[r] ? rMax : arr[r];
                res += rMax - arr[r--];
            }
        }
        return res;
    }
}
