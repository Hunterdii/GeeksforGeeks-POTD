//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;
import java.util.HashMap;


// } Driver Code Ends


class Solution {
    public ArrayList<Integer> longestSubarray(int[] arr, int x) {
        Deque<Integer> minQ = new ArrayDeque<>(), maxQ = new ArrayDeque<>();
        int n = arr.length, start = 0, resStart = 0, resLen = 0;
        for (int end = 0; end < n; end++) {
            while (!minQ.isEmpty() && arr[minQ.peekLast()] > arr[end]) minQ.pollLast();
            while (!maxQ.isEmpty() && arr[maxQ.peekLast()] < arr[end]) maxQ.pollLast();
            minQ.addLast(end);
            maxQ.addLast(end);
            while (arr[maxQ.peekFirst()] - arr[minQ.peekFirst()] > x) {
                if (minQ.peekFirst() == start) minQ.pollFirst();
                if (maxQ.peekFirst() == start) maxQ.pollFirst();
                start++;
            }
            if (end - start + 1 > resLen) {
                resStart = start;
                resLen = end - start + 1;
            }
        }
        ArrayList<Integer> res = new ArrayList<>();
        for (int i = resStart; i < resStart + resLen; i++) res.add(arr[i]);
        return res;
    }
}



//{ Driver Code Starts.
public class Main {

    public static void main(String[] args) throws Exception {
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

            int k = Integer.parseInt(br.readLine());
            // Create Solution object and find closest sum
            Solution ob = new Solution();
            ArrayList<Integer> ans = ob.longestSubarray(arr, k);

            // Print the result as a space-separated string
            for (int num : ans) {
                System.out.print(num + " ");
            }
            System.out.println(); // New line after printing the results
            System.out.println("~");
        }
    }
}

// } Driver Code Ends
