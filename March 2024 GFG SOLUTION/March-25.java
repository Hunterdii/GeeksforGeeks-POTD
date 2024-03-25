//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(read.readLine());
            Solution ob = new Solution();
            ArrayList<String> result = ob.NBitBinary(n);
            for(String value  : result){
                System.out.print(value + " ");
            }
            System.out.println();
        }
    }
}
// } Driver Code Ends


//User function Template for Java


class Solution {
    ArrayList<String> NBitBinary(int N) {
        ArrayList<String> result = new ArrayList<>();
        StringBuilder out = new StringBuilder();
        int on = 0, ze = 0;
        
        dfs(out, on, ze, N, result);
        return result;
    }
    
    void dfs(StringBuilder out, int on, int ze, int n, ArrayList<String> result) {
        if (n == 0) {
            result.add(out.toString());
            return;
        }
        
        if (on == ze) {
            dfs(out.append('1'), on + 1, ze, n - 1, result);
            out.deleteCharAt(out.length() - 1);
        }
        
        if (on > ze) {
            dfs(out.append('1'), on + 1, ze, n - 1, result);
            out.deleteCharAt(out.length() - 1);
            
            dfs(out.append('0'), on, ze + 1, n - 1, result);
            out.deleteCharAt(out.length() - 1);
        }
    }


}
