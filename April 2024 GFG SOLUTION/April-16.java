//{ Driver Code Starts
import java.io.*;
import java.util.*;


class IntArray
{
    public static int[] input(BufferedReader br, int n) throws IOException
    {
        String[] s = br.readLine().trim().split(" ");
        int[] a = new int[n];
        for(int i = 0; i < n; i++)
            a[i] = Integer.parseInt(s[i]);

        return a;
    }

    public static void print(int[] a)
    {
        for(int e : a)
            System.out.print(e + " ");
        System.out.println();
    }

    public static void print(ArrayList<Integer> a)
    {
        for(int e : a)
            System.out.print(e + " ");
        System.out.println();
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            
            int n;
            n = Integer.parseInt(br.readLine());
            
            
            int k;
            k = Integer.parseInt(br.readLine());
            
            
            int[] arr = IntArray.input(br, n);
            
            Solution obj = new Solution();
            int res = obj.minimizeDifference(n, k, arr);
            
            System.out.println(res);
            
        }
    }
}

// } Driver Code Ends


class Solution {
    public int minimizeDifference(int n, int k, int[] arr) {
        int[] prefMini = new int[n];
        int[] suffMaxi = new int[n];
        int[] suffMini = new int[n];
        int[] prefMaxi = new int[n];
        
        prefMaxi[0] = prefMini[0] = arr[0];
        suffMaxi[n - 1] = suffMini[n - 1] = arr[n - 1];
        
        for (int i = 1; i < n; ++i) {
            prefMaxi[i] = Math.max(arr[i], prefMaxi[i - 1]);
            prefMini[i] = Math.min(arr[i], prefMini[i - 1]);
            suffMaxi[n - i - 1] = Math.max(arr[n - i - 1], suffMaxi[n - i]);
            suffMini[n - i - 1] = Math.min(arr[n - i - 1], suffMini[n - i]);
        }
        
        int ans = Integer.MAX_VALUE, i = 0, j = k - 1;

        while (j < n) {
            int mini = Integer.MAX_VALUE, maxi = Integer.MIN_VALUE;
            
            if (i > 0) {
                mini = Math.min(mini, prefMini[i - 1]);
                maxi = Math.max(maxi, prefMaxi[i - 1]);
            }
            if (j < n - 1) {
                mini = Math.min(mini, suffMini[j + 1]);
                maxi = Math.max(maxi, suffMaxi[j + 1]);
            }
            
            ans = Math.min(ans, maxi - mini);
            ++j;
            ++i;
        }
        
        return ans;
    }
}


