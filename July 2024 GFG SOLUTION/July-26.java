//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine().trim());
        while (t-- > 0) {
            String str = sc.nextLine();
            int k = Integer.parseInt(sc.nextLine().trim());
            Solution obj = new Solution();
            if (obj.kPangram(str, k))
                System.out.println("true");
            else
                System.out.println("false");
        }
    }
}
// } Driver Code Ends


// User function Template for Java
class Solution {
    boolean kPangram(String str, int k) {
        Map<Character, Integer> frequency = new HashMap<>();
        for (char c : str.toCharArray()) {
            if (Character.isAlphabetic(c)) {
                frequency.put(c, frequency.getOrDefault(c, 0) + 1);
            }
        }

        int cnt = 0;
        int uniq = 0;
        for (Map.Entry<Character, Integer> entry : frequency.entrySet()) {
            if (Character.isAlphabetic(entry.getKey())) {
                cnt += entry.getValue();
                uniq++;
            }
        }

        return cnt >= 26 && (26 - uniq) <= k;
    }
}
