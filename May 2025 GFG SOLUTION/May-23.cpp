class Solution {
  public:
    int noOfWays(int m, int n, int x) {
        const int mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(x + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= x; ++j)
                for (int k = 1; k <= m && k <= j; ++k)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod;
        return dp[n][x];
    }
};

2)
class Solution {
  public:
    int dp[51][2501];
    int mod = 1e9 + 7;
    
    int solve(int n, int x, int m) {
        if (n == 0) return x == 0;
        if (x < 0) return 0;
        if (dp[n][x] != -1) return dp[n][x];
        int res = 0;
        for (int i = 1; i <= m; ++i)
            res = (res + solve(n - 1, x - i, m)) % mod;
        return dp[n][x] = res;
    }

    int noOfWays(int m, int n, int x) {
        memset(dp, -1, sizeof(dp));
        return solve(n, x, m);
    }
};

3)
class Solution {
  public:
    int noOfWays(int m, int n, int x) {
        const int mod = 1e9 + 7;
        vector<int> dp(x + 1), tmp(x + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            fill(tmp.begin(), tmp.end(), 0);
            for (int j = 1; j <= x; ++j)
                for (int k = 1; k <= m && k <= j; ++k)
                    tmp[j] = (tmp[j] + dp[j - k]) % mod;
            dp = tmp;
        }
        return dp[x];
    }
};
