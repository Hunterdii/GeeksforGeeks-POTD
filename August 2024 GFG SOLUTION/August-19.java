//{ Driver Code Starts
// Initial Template for Java

/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        int t = Integer.parseInt(in.readLine().trim());
        while (t-- > 0) {
            String line = in.readLine();
            String[] tokens = line.split(" ");

            // Create an ArrayList to store the integers
            ArrayList<Integer> array = new ArrayList<>();

            // Parse the tokens into integers and add to the array
            for (String token : tokens) {
                array.add(Integer.parseInt(token));
            }

            int[] arr = new int[array.size()];
            int idx = 0;
            for (int i : array) arr[idx++] = i;

            int key = Integer.parseInt(in.readLine().trim());
            Solution ob = new Solution();
            out.println(ob.kthSmallest(arr, key));
        }
        out.flush();
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    public static int kthSmallest(int[] arr, int k) {
        int minElement = Integer.MAX_VALUE;
        int maxElement = Integer.MIN_VALUE;

        for (int num : arr) {
            if (num < minElement) {
                minElement = num;
            }
            if (num > maxElement) {
                maxElement = num;
            }
        }

        int range = maxElement - minElement + 1;
        int[] freq = new int[range];

        for (int num : arr) {
            freq[num - minElement]++;
        }

        int count = 0;
        for (int i = 0; i < range; i++) {
            count += freq[i];
            if (count >= k) {
                return i + minElement;
            }
        }

        return -1;
    }
}
