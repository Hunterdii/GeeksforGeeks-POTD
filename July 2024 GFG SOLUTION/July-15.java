//{ Driver Code Starts
import java.util.*;

class GFG {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();

        while (tc-- > 0) {
            int s = sc.nextInt();
            int d = sc.nextInt();

            Solution obj = new Solution();
            String res = obj.smallestNumber(s, d);

            System.out.println(res);
        }
    }
}
// } Driver Code Ends



class Solution {
    public String smallestNumber(int s, int d) {
        if (s > 9 * d) return "-1";

        char[] result = new char[d];
        Arrays.fill(result, '0');
        s--;

        for (int i = d - 1; i >= 0; i--) {
            if (s > 9) {
                result[i] = '9';
                s -= 9;
            } else {
                result[i] = (char) ('0' + s);
                s = 0;
            }
        }
        result[0] = (char) (result[0] + 1); 
        return new String(result);
    }
}
