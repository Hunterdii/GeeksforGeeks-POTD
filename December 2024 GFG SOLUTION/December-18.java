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
            int ans = sln.findPages(a, k);

            System.out.println(ans);
            System.out.println("~");
        }
    }
}
// } Driver Code Ends



//Back-end complete function Template for Java

class Solution {
    public static int findPages(int[] arr, int k) {
        int n = arr.length;
        if (k > n) return -1; 

        int low = Arrays.stream(arr).max().getAsInt(); 
        int high = Arrays.stream(arr).sum(); 

        while (low < high) {
            int mid = (low + high) / 2;
            int students = 1, sum = 0;

            for (int pages : arr) {
                if ((sum + pages) > mid) {
                    students++;
                    sum = pages;
                } else {
                    sum += pages;
                }
            }

            if (students > k) low = mid + 1;
            else high = mid;
        }
        return low;
    }
}

