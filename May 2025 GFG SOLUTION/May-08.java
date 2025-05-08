//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(reader.readLine().trim());

        Solution solution = new Solution();
        while (t-- > 0) {
            String input = reader.readLine().trim();
            String[] parts = input.split("\\s+");
            int[] arr = Arrays.stream(parts).mapToInt(Integer::parseInt).toArray();

            System.out.println(solution.findMissing(arr));

            System.out.println("~");
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    public int findMissing(int[] a) {
        int n = a.length;
        int d1 = a[1] - a[0], d2 = a[n-1] - a[n-2], d3 = (a[n-1] - a[0]) / n;
        int d = (d1==d2 || d1==d3) ? d1 : d2;
        if (d == 0) return a[0];
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >>> 1;
            if ((a[mid] - a[0]) / d == mid) lo = mid + 1;
            else hi = mid - 1;
        }
        return a[0] + lo * d;
    }
}
