//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(read.readLine());
            Solution ob = new Solution();
            System.out.println(ob.firstElement(n));
        }
    }
}
// } Driver Code Ends


// User function Template for Java
class Solution {
    static int firstElement(int n) {
        int mod = 1000000007;
        if (n <= 2) return 1;
        int one = 1, sum = 0;
        int two = 1;
        for (int i = 3; i <= n; i++) {
            sum = (one + two) % mod;
            one = two;
            two = sum;
        }
        return sum;
    }
}
