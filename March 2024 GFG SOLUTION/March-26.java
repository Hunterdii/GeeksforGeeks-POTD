//{ Driver Code Starts
import java.util.*;

public class GFG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            String s = sc.next();
            Solution ss = new Solution();
            boolean result = ss.isAdditiveSequence(s);
            System.out.println((result == true ? 1 : 0));
        }
        sc.close();
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    public boolean isAdditiveSequence(String n) {
        if (n.charAt(0) == '0') return false;
        int len = n.length();
        for (int i = 1; i < len - 1; i++) {
            String n1 = n.substring(0, i);
            for (int j = i + 1; j < len; j++) {
                String n2 = n.substring(i, j);
                if (findRec(n1, n2, n.substring(j), false)) return true;
            }
        }
        return false;
    }

    private boolean findRec(String n1, String n2, String s, boolean found) {
        if (s.length() == 0 && found) return true;
        String n3 = add(n1, n2);
        int idx = Math.min(s.length(), n3.length());
        if (s.substring(0, idx).equals(n3))
            return findRec(n2, n3, s.substring(idx), true);
        return false;
    }

    private String add(String n1, String n2) {
        StringBuilder temp = new StringBuilder();
        int carry = 0;
        int n1Size = n1.length() - 1;
        int n2Size = n2.length() - 1;
        while (n1Size >= 0 || n2Size >= 0) {
            int digitSum = carry;
            if (n1Size >= 0) digitSum += n1.charAt(n1Size--) - '0';
            if (n2Size >= 0) digitSum += n2.charAt(n2Size--) - '0';
            temp.append((char) (digitSum % 10 + '0'));
            carry = digitSum / 10;
        }
        if (carry > 0) temp.append((char) (carry + '0'));
        return temp.reverse().toString();
    }
}
