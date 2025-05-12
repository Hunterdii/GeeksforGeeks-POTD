//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.lang.*;
import java.util.*;


// } Driver Code Ends

class Solution {
    public static int kthLargest(int[] arr, int k) {
        int[] p = new int[arr.length + 1];
        for (int i = 0; i < arr.length; ++i) p[i + 1] = p[i] + arr[i];
        PriorityQueue<Integer> q = new PriorityQueue<>();
        for (int i = 0; i < arr.length; ++i)
            for (int j = i + 1; j <= arr.length; ++j) {
                q.add(p[j] - p[i]);
                if (q.size() > k) q.poll();
            }
        return q.peek();
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
            int k = Integer.parseInt(br.readLine());

            int[] arr = new int[array.size()];
            int idx = 0;
            for (int i : array) arr[idx++] = i;
            Solution obj = new Solution();
            int res = obj.kthLargest(arr, k);

            System.out.println(res);

            System.out.println("~");
        }
    }
}

// } Driver Code Ends


// 2) Solution @itsjomon

class Solution {
    public static int kthLargest(int[] arr, int k) {
        // code here
        int n = arr.length;
        PriorityQueue<Integer> q = new PriorityQueue<>();
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum = sum + arr[j];
                
                if(q.size() < k){
                    q.offer(sum);
                }else if(sum > q.peek()){
                    q.poll();
                    q.offer(sum);
                }
            }
        }
        return q.peek();
    }
}
