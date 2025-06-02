class Solution {
    public int uniquePaths(int[][] grid) {
        int r = grid.length, c = grid[0].length;
        int[] dp = new int[c];
        dp[0] = grid[0][0] == 0 ? 1 : 0;
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                if (grid[i][j] == 1) dp[j] = 0;
                else if (j > 0) dp[j] += dp[j - 1];
        return dp[c - 1];
    }
}
