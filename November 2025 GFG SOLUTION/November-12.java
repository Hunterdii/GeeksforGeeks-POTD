class Solution {
    public boolean wildCard(String txt, String pat) {
        int n = txt.length(), m = pat.length();
        boolean[][] dp = new boolean[n + 1][m + 1];
        dp[0][0] = true;
        for (int j = 1; j <= m; j++) 
            if (pat.charAt(j - 1) == '*') dp[0][j] = dp[0][j - 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (pat.charAt(j - 1) == '*') 
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                else if (pat.charAt(j - 1) == '?' || txt.charAt(i - 1) == pat.charAt(j - 1)) 
                    dp[i][j] = dp[i - 1][j - 1];
            }
        }
        return dp[n][m];
    }
}
