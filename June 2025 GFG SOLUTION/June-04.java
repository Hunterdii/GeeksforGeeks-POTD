class Solution {
    int lcsOf3(String s1, String s2, String s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        int[][] prev = new int[n2 + 1][n3 + 1];
        int[][] curr = new int[n2 + 1][n3 + 1];
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                for (int k = 1; k <= n3; ++k) {
                    if (s1.charAt(i - 1) == s2.charAt(j - 1) && 
                        s2.charAt(j - 1) == s3.charAt(k - 1))
                        curr[j][k] = 1 + prev[j - 1][k - 1];
                    else
                        curr[j][k] = Math.max(
                            Math.max(prev[j][k], curr[j - 1][k]),
                            curr[j][k - 1]
                        );
                }
            }
            int[][] temp = prev;
            prev = curr;
            curr = temp;
        }
        return prev[n2][n3];
    }
}
