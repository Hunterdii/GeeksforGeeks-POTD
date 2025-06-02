class Solution {
  public:
    int uniquePaths(vector<vector<int>> &grid) {
        int r = grid.size(), c = grid[0].size();
        vector<int> dp(c);
        dp[0] = grid[0][0] == 0;
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                if (grid[i][j]) dp[j] = 0;
                else if (j) dp[j] += dp[j - 1];
        return dp[c - 1];
    }
};

2)
class Solution {
  public:
    int uniquePaths(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<vector<int>> dp(r, vector<int>(c, 0));
        if (grid[0][0]) return 0;
        dp[0][0] = 1;
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                if (!grid[i][j]) {
                    if (i) dp[i][j] += dp[i - 1][j];
                    if (j) dp[i][j] += dp[i][j - 1];
                }
        return dp[r - 1][c - 1];
    }
};

3)
class Solution {
  public:
    int uniquePaths(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        if (grid[0][0] == 1) return 0;
        grid[0][0] = 1;
        for (int j = 1; j < c; ++j)
            grid[0][j] = (grid[0][j] == 1 ? 0 : grid[0][j - 1]);
        for (int i = 1; i < r; ++i)
            grid[i][0] = (grid[i][0] == 1 ? 0 : grid[i - 1][0]);
        for (int i = 1; i < r; ++i)
            for (int j = 1; j < c; ++j)
                grid[i][j] = (grid[i][j] == 1 ? 0 : grid[i - 1][j] + grid[i][j - 1]);
        return grid[r - 1][c - 1];
    }
};

4)
class Solution {
  public:
    int r, c;
    vector<vector<int>> memo;
    vector<vector<int>> *g;

    int dfs(int i, int j) {
        if (i < 0 || j < 0 || (*g)[i][j] == 1) return 0;
        if (i == 0 && j == 0) return 1;
        if (memo[i][j] != -1) return memo[i][j];
        int up = dfs(i - 1, j);
        int left = dfs(i, j - 1);
        return memo[i][j] = up + left;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        g = &grid;
        r = grid.size(); c = grid[0].size();
        memo.assign(r, vector<int>(c, -1));
        return dfs(r - 1, c - 1);
    }
};


