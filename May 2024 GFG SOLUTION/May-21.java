//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

public class GFG {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String[] inputLine;
            inputLine = br.readLine().trim().split(" ");
            int n = Integer.parseInt(inputLine[0]);
            int[] arr = new int[n];
            inputLine = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }
            inputLine = br.readLine().trim().split(" ");
            int k = Integer.parseInt(inputLine[0]);
            int x = Integer.parseInt(inputLine[1]);

            int[] ans = new Solution().printKClosest(arr, n, k, x);
            for (int xx : ans) {
                System.out.print(xx + " ");
            }
            System.out.println();
        }
    }
}

// } Driver Code Ends


class Solution {
    private int findCrossOver(int[] arr, int low, int high, int x) {
        if (arr[high] <= x) {
            return high;
        }
        if (arr[low] > x) {
            return low;
        }
        int mid = (low + high) / 2;
        if (arr[mid] <= x && arr[mid + 1] > x) {
            return mid;
        } else if (arr[mid] < x) {
            return findCrossOver(arr, mid + 1, high, x);
        }
        return findCrossOver(arr, low, mid - 1, x);
    }

    int[] printKClosest(int[] arr, int n, int k, int x) {
      
        int[] result = new int[k];
        List<Integer> closest = new ArrayList<>();

        
        int l = findCrossOver(arr, 0, n - 1, x);

        int r = l + 1; 
        int count = 0; 

        if (arr[l] == x) { 
            l--;
        }

        
        while (l >= 0 && r < n && count < k) {
            if (x - arr[l] < arr[r] - x) {
                closest.add(arr[l]);
                l--;
            } else {
                closest.add(arr[r]);
                r++;
            }
            count++;
        }

        
        while (count < k && l >= 0) {
            closest.add(arr[l]);
            l--;
            count++;
        }

       
        while (count < k && r < n) {
            closest.add(arr[r]);
            r++;
            count++;
        }

       
        for (int i = 0; i < k; i++) {
            result[i] = closest.get(i);
        }

        return result;
    }
}
