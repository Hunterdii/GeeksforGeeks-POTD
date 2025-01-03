//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());

        while (tc-- > 0) {
            String s[] = br.readLine().split(" ");
            int arr[] = new int[s.length];

            for (int i = 0; i < arr.length; i++) {
                arr[i] = Integer.parseInt(s[i]);
            }
            int k = Integer.parseInt(br.readLine());

            Solution obj = new Solution();
            System.out.println(obj.subarrayXor(arr, k));
            System.out.println("~");
        }
    }
}
// } Driver Code Ends

class Solution {
    public long subarrayXor(int[] arr, int k) {
        long res = 0, prefXOR = 0;
        Map<Long, Integer> mp = new HashMap<>();
        mp.put(0L, 1);  
        for (int val : arr) {
            prefXOR ^= val; 
            res += mp.getOrDefault(prefXOR ^ k, 0); 
            mp.put(prefXOR, mp.getOrDefault(prefXOR, 0) + 1); 
        }
        
        return res;
    }
}
