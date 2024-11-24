//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String[] s = br.readLine().trim().split(" ");
            int arr[] = new int[s.length];
            for (int i = 0; i < s.length; i++) {
                arr[i] = Integer.parseInt(s[i]);
            }

            int[] ans = new Solution().constructLowerArray(arr);
            for (int i = 0; i < arr.length; i++) {
                System.out.print(ans[i] + " ");
            }
            System.out.println();
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    private int[] bit;

    private void update(int index, int value, int n) {
        for (; index <= n; index += index & (-index)) {
            bit[index] += value;
        }
    }

    private int get(int index) {
        int sum = 0;
        for (; index > 0; index -= index & (-index)) {
            sum += bit[index];
        }
        return sum;
    }

    public int[] constructLowerArray(int[] nums) {
        int n = nums.length;
        bit = new int[n + 1];
        int[] ans = new int[n];

        List<int[]> valueIndexPairs = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            valueIndexPairs.add(new int[]{nums[i], i});
        }

        Collections.sort(valueIndexPairs, Comparator.comparingInt(a -> a[0]));

        Map<Integer, Integer> rank = new HashMap<>();
        for (int i = 0; i < n; i++) {
            rank.put(valueIndexPairs.get(i)[0], i + 1);
        }

        for (int i = n - 1; i >= 0; i--) {
            int index = rank.get(nums[i]);
            ans[i] = get(index - 1);
            update(index, 1, n);
        }

        return ans;
    }
}
