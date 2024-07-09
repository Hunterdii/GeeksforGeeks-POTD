//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

public class GFG {
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

            out.println(new Solution().threeSumClosest(arr, key));
        }
        out.close();
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    public int threeSumClosest(int[] arr, int target) {
        Arrays.sort(arr);
        int closest_sum = Integer.MAX_VALUE;
        int n = arr.length;

        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1, right = n - 1;

            while (left < right) {
                int current_sum = arr[i] + arr[left] + arr[right];

                if (current_sum == target) {
                    return current_sum;
                }

                if (Math.abs(current_sum - target) < Math.abs(closest_sum - target) || 
                   (Math.abs(current_sum - target) == Math.abs(closest_sum - target) && current_sum > closest_sum)) {
                    closest_sum = current_sum;
                }

                if (current_sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return closest_sum;
    }
}
