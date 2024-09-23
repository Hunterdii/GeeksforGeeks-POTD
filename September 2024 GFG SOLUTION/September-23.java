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
            String[] str = br.readLine().split(" ");

            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(str[i]);
            }

            int[] ans = new Solve().findTwoElement(a);
            System.out.println(ans[0] + " " + ans[1]);
        }
    }
}
// } Driver Code Ends

class Solve {
    int[] findTwoElement(int arr[]) {
        int n = arr.length;
        int xor_all = 0, xor1 = 0, xor2 = 0;

        for (int i = 0; i < n; i++) {
            xor_all ^= arr[i];     
            xor_all ^= (i + 1);    
        }

        int set_bit = xor_all & ~(xor_all - 1);

        for (int i = 0; i < n; i++) {
            if ((arr[i] & set_bit) != 0)  
                xor1 ^= arr[i];
            else                          
                xor2 ^= arr[i];

            if (((i + 1) & set_bit) != 0)  
                xor1 ^= (i + 1);
            else                           
                xor2 ^= (i + 1);
        }

        int repeating = 0, missing = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == xor1) {
                repeating = xor1;
                missing = xor2;
                break;
            } else if (arr[i] == xor2) {
                repeating = xor2;
                missing = xor1;
                break;
            }
        }

        return new int[]{repeating, missing};
    }
}
