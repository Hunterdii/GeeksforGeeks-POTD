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
            
            
            int d;
            d = Integer.parseInt(br.readLine());
            
            
            int[] arr = IntArray.input(br, n);
            
            Solution obj = new Solution();
            int res = obj.countPartitions(n, d, arr);
            
            System.out.println(res);
            
        }
    }
}

// } Driver Code Ends



class Solution {
    private static final int MOD = 1000000007;

    public static int findWays(int[] num, int tar) {
        int n = num.length;
        int[] dp = new int[tar + 1];
        
        dp[0] = num[0] == 0 ? 2 : 1; 

        if (num[0] != 0 && num[0] <= tar) {
            dp[num[0]] = 1;
        }

        for (int ind = 1; ind < n; ind++) {
            int[] newDp = new int[tar + 1];
            for (int target = 0; target <= tar; target++) {
                int notTaken = dp[target];
                int taken = (target >= num[ind]) ? dp[target - num[ind]] : 0;

                newDp[target] = (notTaken + taken) % MOD;
            }
            dp = newDp; 
        }
        
        return dp[tar];
    }

    public int countPartitions(int n, int d, int[] arr) {
        int sum = Arrays.stream(arr).sum();
        if (sum < d || (sum - d) % 2 != 0) {
            return 0;
        }
        return findWays(arr, (sum - d) / 2);
    }

    public static void main(String[] args) {
        // Driver code
        java.util.Scanner sc = new java.util.Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int d = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }
            Solution obj = new Solution();
            System.out.println(obj.countPartitions(n, d, arr));
        }
        sc.close();
    }
}

