//{ Driver Code Starts
//Initial Template for Java


import java.util.*;
import java.io.*;
import java.lang.*;

class Main
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t  =Integer.parseInt(read.readLine());
        
        while(t-- > 0)
        {
            String st[] = read.readLine().trim().split(" ");
            int N = Integer.parseInt(st[0]);
            int M = Integer.parseInt(st[1]);
            
            int arr1[] = new int[N];
            int arr2[] = new int[M];
            
            st = read.readLine().trim().split(" ");
            for(int i = 0; i < N; i++)
              arr1[i] = Integer.parseInt(st[i]);
            
            st = read.readLine().trim().split(" ");  
            for(int i = 0; i< M; i++)
              arr2[i] = Integer.parseInt(st[i]);
            
            Solution obj = new Solution();
            ArrayList<Integer> res = new ArrayList<Integer>();
            res = obj.findUnion(arr1, arr2, N, M);
            for(int i = 0;i<res.size();i++)
                System.out.print(res.get(i) + " ");
            System.out.println(); 
        }
    }
}



// } Driver Code Ends


//User function Template for Java

arr1,arr2 : the arrays
n, m: size of arrays
1) class Solution {
    //Function to return a list containing the union of the two arrays.
    public static ArrayList<Integer> findUnion(int arr1[], int arr2[], int n, int m) {
        Arrays.sort(arr1);
        Arrays.sort(arr2);
        
        ArrayList<Integer> ans = new ArrayList<>();
        
        int i = 0, j = 0;
        
        while (i < n && j < m) {
            if (arr1[i] < arr2[j]) {
                ans.add(arr1[i]);
                i++;
            } else if (arr1[i] > arr2[j]) {
                ans.add(arr2[j]);
                j++;
            } else {
                ans.add(arr1[i]);
                i++;
                j++;
            }
        }
        
        while (i < n) {
            ans.add(arr1[i]);
            i++;
        }
        
        while (j < m) {
            ans.add(arr2[j]);
            j++;
        }
        
        // Remove duplicates
        ArrayList<Integer> result = new ArrayList<>();
        for (int k = 0; k < ans.size(); k++) {
            if (k == 0 || !ans.get(k).equals(ans.get(k - 1))) {
                result.add(ans.get(k));
            }
        }
        
        return result; 
    }
}



2) class Solution
{
    //Function to return a list containing the union of the two arrays.
    public static ArrayList<Integer> findUnion(int arr1[], int arr2[], int n, int m)
    {
        Set<Integer> set = new HashSet<>();
        ArrayList<Integer> ans = new ArrayList<>();
        
        for (int i = 0; i < n; i++)
            set.add(arr1[i]);
        
        for (int i = 0; i < m; i++)
            set.add(arr2[i]);
            
        for (int num : set)
            ans.add(num);
        
        Collections.sort(ans);
        
        return ans; 
    }
}

