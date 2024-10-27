//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.lang.*;
import java.util.*;


// } Driver Code Ends

class Solution {
    public boolean findTriplet(int[] arr) {
        int n = arr.length;
        if (n < 3) return false;

        Arrays.sort(arr); // Sort array

        for (int i = n - 1; i >= 2; i--) {
            int target = arr[i];
            int left = 0, right = i - 1;

            while (left < right) {
                int sum = arr[left] + arr[right];

                if (sum == target) return true;
                if (sum < target) {
                    left++; 
                } else {
                    right--; 
                }
            }
        }
        return false; 
    }
}

//{ Driver Code Starts.

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String line = br.readLine();
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
            Solution obj = new Solution();
            boolean res = obj.findTriplet(arr);
            if (res)
                System.out.println("true");
            else
                System.out.println("false");

            System.out.println("~");
        }
    }
}

// } Driver Code Ends
