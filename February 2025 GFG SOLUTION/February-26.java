//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        while (t-- > 0) {
            String line = sc.nextLine();
            String[] input = line.split(" ");
            int[] arr = Arrays.stream(input).mapToInt(Integer::parseInt).toArray();
            Solution solution = new Solution();
            ArrayList<Integer> result = solution.maxOfMins(arr);
            for (int val : result) {
                System.out.print(val + " ");
            }
            System.out.println();
            System.out.println("~");
        }
        sc.close();
    }
}
// } Driver Code Ends



class Solution {
    public ArrayList<Integer> maxOfMins(int[] arr) {
        int n = arr.length;
        int[] res = new int[n], len = new int[n];
        Stack<Integer> s = new Stack<>();
        for (int i = 0; i <= n; i++) {
            while (!s.isEmpty() && (i == n || arr[s.peek()] >= arr[i])) {
                int j = s.pop();
                len[j] = s.isEmpty() ? i : i - s.peek() - 1;
            }
            if (i < n) s.push(i);
        }
        for (int i = 0; i < n; i++) res[len[i] - 1] = Math.max(res[len[i] - 1], arr[i]);
        for (int i = n - 2; i >= 0; i--) res[i] = Math.max(res[i], res[i + 1]);
        ArrayList<Integer> ans = new ArrayList<>();
        for (int r : res) ans.add(r);
        return ans;
    }
}
