//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // Read the number of test cases (t)
        int t = Integer.parseInt(br.readLine().trim());

        while (t-- > 0) {
            int k = Integer.parseInt(br.readLine().trim());
            String input = br.readLine().trim();

            // Split the input line into integers and store them in the array
            String[] tokens = input.split(" ");
            int[] arr = new int[tokens.length];
            for (int i = 0; i < tokens.length; i++) {
                arr[i] = Integer.parseInt(tokens[i]);
            }

            // Create an instance of the Solution class
            Solution ob = new Solution();

            // Call the getMinDiff method
            int res = ob.getMinDiff(k, arr);

            // Print the result
            System.out.println(res);
            System.out.println("~");
        }
    }
}

// } Driver Code Ends

class Solution {
    public int getMinDiff(int k, int[] arr) {
        List<int[]> modified = new ArrayList<>();
        int n = arr.length;
        int[] count = new int[n];

        for (int i = 0; i < n; i++) {
            modified.add(new int[]{arr[i] - k, i});
            modified.add(new int[]{arr[i] + k, i});
        }

        modified.sort((a, b) -> Integer.compare(a[0], b[0]));

        int left = 0, elementsInRange = 0, ans = Integer.MAX_VALUE;

        for (int right = 0; right < modified.size(); right++) {
            if (count[modified.get(right)[1]]++ == 0) {
                elementsInRange++;
            }

            while (elementsInRange == n) {
                ans = Math.min(ans, modified.get(right)[0] - modified.get(left)[0]);

                if (--count[modified.get(left)[1]] == 0) {
                    elementsInRange--;
                }
                left++;
            }
        }

        return ans;
    }
}
