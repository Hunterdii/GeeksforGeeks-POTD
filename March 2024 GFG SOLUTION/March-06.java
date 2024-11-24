//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0)
        {
            String s, patt;
            s = sc.next();
            patt = sc.next();
            
            Solution ob = new Solution();
            
            ArrayList<Integer> res = ob.search(patt, s);
            
            for(int i = 0;i<res.size();i++)
                System.out.print(res.get(i) + " ");
            System.out.println();    
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution {
    
    ArrayList<Integer> search(String pattern, String text) {
        int n = text.length();
        int m = pattern.length();
        ArrayList<Integer> ans = new ArrayList<>();
        
        for (int i = 0; i < n - m + 1; i++) {
            // check if first and last character match then only check the whole string to reduce time complexity
            if (pattern.charAt(0) == text.charAt(i) && pattern.charAt(m - 1) == text.charAt(i + m - 1)) {
                if (pattern.equals(text.substring(i, i + m))) {
                    ans.add(i + 1);
                }
            }
        }
        
        return ans;
    }
}
