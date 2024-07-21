//{ Driver Code Starts
import java.util.*;

public class GFG {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();

        while (tc-- > 0) {
            int n = sc.nextInt();
            List<Integer> list = new ArrayList<>();

            for (int i = 0; i < n; i++) list.add(sc.nextInt());

            Solution obj = new Solution();
            long ans = obj.findMaxProduct(list);

            System.out.println(ans);
        }
    }
}
// } Driver Code Ends


class Solution {
    private final int mod = (int) 1e9 + 7;

    public long findMaxProduct(List<Integer> arr) {
        int negCount = 0;
        int maxNeg = Integer.MIN_VALUE;
        long posProduct = 1;
        long negProduct = 1;
        boolean hasNonZero = false;

        for (int num : arr) {
            if (num < 0) {
                negCount++;
                maxNeg = Math.max(maxNeg, num);
            }
        }

        boolean skipMaxNeg = (negCount % 2 == 1);

        for (int num : arr) {
            if (num < 0) {
                if (skipMaxNeg && num == maxNeg) {
                    skipMaxNeg = false;
                    continue;
                }
                negProduct = (negProduct * Math.abs(num)) % mod;
            } else if (num > 0) {
                posProduct = (posProduct * num) % mod;
                hasNonZero = true;
            }
        }

        if (!hasNonZero && negCount <= 1) return 0;
        return (negProduct * posProduct) % mod;
    }
}
