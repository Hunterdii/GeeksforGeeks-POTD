//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(in.readLine());

            Solution ob = new Solution();
            List<Integer> ans = new ArrayList<Integer>();
            StringBuilder out = new StringBuilder();
            ans = ob.jugglerSequence(n);
            for (int i = 0; i < ans.size(); i++) out.append(ans.get(i) + " ");
            System.out.println(out);
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    static List<Integer> jugglerSequence(int n) {
        List<Integer> ans = new ArrayList<>();
        ans.add(n);

        while (ans.get(ans.size() - 1) > 1) {
            double sqrt_n = Math.sqrt(ans.get(ans.size() - 1));
            int next_term = (ans.get(ans.size() - 1) % 2 == 0) ? (int) sqrt_n : (int) Math.pow(sqrt_n, 3);
            ans.add(next_term);
        }

        return ans;
    }
}
