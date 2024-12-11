//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim()); // Inputting the testcases

        while (t-- > 0) {
            String arr1[] = br.readLine().trim().split(" ");
            String arr2[] = br.readLine().trim().split(" ");

            int a[] = new int[arr1.length];
            int b[] = new int[arr2.length];

            for (int i = 0; i < a.length; i++) a[i] = Integer.parseInt(arr1[i]);
            for (int i = 0; i < b.length; i++) b[i] = Integer.parseInt(arr2[i]);

            Solution ob = new Solution();
            ob.mergeArrays(a, b);

            StringBuffer str = new StringBuffer();
            for (int i = 0; i < a.length; i++) {
                str.append(a[i] + " ");
            }
            System.out.println(str);
            str = new StringBuffer();
            for (int i = 0; i < b.length; i++) {
                str.append(b[i] + " ");
            }
            System.out.println(str);
        }
    }
}

// } Driver Code Ends

class Solution {
    private int nextGap(int gap) {
        return (gap <= 1) ? 0 : (gap / 2) + (gap % 2);
    }
    public void mergeArrays(int[] a, int[] b) {
        int n = a.length, m = b.length;
        int gap = n + m;

        for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) {
            int i, j;
            for (i = 0; i + gap < n; i++) {
                if (a[i] > a[i + gap]) {
                    int temp = a[i];
                    a[i] = a[i + gap];
                    a[i + gap] = temp;
                }
            }
            for (j = (gap > n ? gap - n : 0); i < n && j < m; i++, j++) {
                if (a[i] > b[j]) {
                    int temp = a[i];
                    a[i] = b[j];
                    b[j] = temp;
                }
            }
            for (j = 0; j + gap < m; j++) {
                if (b[j] > b[j + gap]) {
                    int temp = b[j];
                    b[j] = b[j + gap];
                    b[j + gap] = temp;
                }
            }
        }
    }
}
