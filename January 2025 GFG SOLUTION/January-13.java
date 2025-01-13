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


// User function Template for Java
class Solution {
    public int maxWater(int[] arr) {
        int l = 0, r = arr.length - 1, res = 0;
        while (l < r) res = Math.max(res, (r - l) * (arr[l] < arr[r] ? arr[l++] : arr[r--]));
        return res;
    }
}

2)
class Solution {
    public int maxWater(int[] arr) {
        int l = 0, r = arr.length - 1, res = 0;
        while (l < r) {
            res = Math.max(res, (r - l) * Math.min(arr[l], arr[r]));
            if (arr[l] < arr[r])
                l++;
            else
                r--;
        }
        return res;
    }
}
