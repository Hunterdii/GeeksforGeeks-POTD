//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int g = 0; g < t; g++) {
            String[] str = (br.readLine()).trim().split(" ");
            int x[] = new int[str.length];
            for (int i = 0; i < str.length; i++) x[i] = Integer.parseInt(str[i]);
            str = (br.readLine()).trim().split(" ");
            int[] y = new int[str.length];
            for (int i = 0; i < str.length; i++) {
                y[i] = Integer.parseInt(str[i]);
            }
            System.out.println(new Solution().countPairs(x, y, x.length, y.length));
        }
    }
}

// } Driver Code Ends


//Back-end complete function Template for Java
class Solution {
    public long countPairs(int[] arr, int[] brr, int M, int N) {
        int[] NoOfY = new int[5];
        for (int i = 0; i < N; i++) {
            if (brr[i] < 5) NoOfY[brr[i]]++;
        }
        Arrays.sort(brr);
        long total_pairs = 0;

        for (int x : arr) {
            if (x == 0) continue;
            if (x == 1) {
                total_pairs += NoOfY[0];
                continue;
            }

            int idx = Arrays.binarySearch(brr, x);
            if (idx < 0) idx = -idx - 1;
            else while (idx < N && brr[idx] == x) idx++;
            
            long count = N - idx;
            count += (NoOfY[0] + NoOfY[1]);

            if (x == 2) count -= (NoOfY[3] + NoOfY[4]);
            if (x == 3) count += NoOfY[2];

            total_pairs += count;
        }

        return total_pairs;
    }
}
