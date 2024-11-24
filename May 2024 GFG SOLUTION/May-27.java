//{ Driver Code Starts
import java.io.*;
import java.util.*;

class IntArray {
    public static int[] input(BufferedReader br, int n) throws IOException {
        String[] s = br.readLine().trim().split(" ");
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = Integer.parseInt(s[i]);

        return a;
    }

    public static void print(int[] a) {
        for (int e : a) System.out.print(e + " ");
        System.out.println();
    }

    public static void print(ArrayList<Integer> a) {
        for (int e : a) System.out.print(e + " ");
        System.out.println();
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {

            int n;
            n = Integer.parseInt(br.readLine());

            int[] a = IntArray.input(br, n);

            Solution obj = new Solution();
            int res = obj.longestSubseq(n, a);

            System.out.println(res);
        }
    }
}

// } Driver Code Ends


class Solution {
    public int longestSubseq(int n, int[] a) {
        HashMap<Integer, Integer> dp = new HashMap<>();
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            int x = a[i];
            int len1 = dp.getOrDefault(x - 1, 0) + 1;
            int len2 = dp.getOrDefault(x + 1, 0) + 1;
            dp.put(x, Math.max(dp.getOrDefault(x, 0), Math.max(len1, len2)));
            ans = Math.max(ans, dp.get(x));
        }

        return ans;
    }
}
