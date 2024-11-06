//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testCases = Integer.parseInt(br.readLine().trim());

        while (testCases-- > 0) {
            String[] str = br.readLine().trim().split(" ");
            int[] arr = new int[str.length];
            for (int i = 0; i < str.length; i++) {
                arr[i] = Integer.parseInt(str[i]);
            }

            Solution ob = new Solution();
            List<Integer> result = ob.findSplit(arr);

            if (result.get(0) == -1 && result.get(1) == -1) {
                System.out.println("false");
            } else {
                System.out.println("true");
            }
            System.out.println("~");
        }
    }
}

// } Driver Code Ends


// User function Template for Java
class Solution {
    public List<Integer> findSplit(int[] arr) {
        int n = arr.length;
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += arr[i];
        }

        if (totalSum % 3 != 0)
            return Arrays.asList(-1, -1);

        int target = totalSum / 3;
        int currentSum = 0;
        int countFirst = 0;  

        for (int i = 0; i < n; i++) {
            currentSum += arr[i];

            if (currentSum == 2 * target && countFirst > 0)
                return Arrays.asList(countFirst - 1, i);  

            if (currentSum == target) {
                countFirst++;  
            }
        }

        return Arrays.asList(-1, -1);
    }
}
