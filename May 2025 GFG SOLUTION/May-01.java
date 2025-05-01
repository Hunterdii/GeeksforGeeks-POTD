//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    // Driver code
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());

            ArrayList<Integer> ans = new Solution().nthRowOfPascalTriangle(n);
            printAns(ans);

            System.out.println("~");
        }
    }

    public static void printAns(ArrayList<Integer> ans) {
        for (Integer x : ans) {
            System.out.print(x + " ");
        }
        System.out.println();
    }
}

// } Driver Code Ends


// User function Template for Java
class Solution {
    public ArrayList<Integer> nthRowOfPascalTriangle(int n) {
        ArrayList<Integer> row=new ArrayList<>();
        long v=1;
        for(int i=0;i<n;++i){
            row.add((int)v);
            v=v*(n-1-i)/(i+1);
        }
        return row;
    }
}
