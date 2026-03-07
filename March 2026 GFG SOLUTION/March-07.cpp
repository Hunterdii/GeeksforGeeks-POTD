class Solution {
public:
    int noOfWays(int m, int n, int x) {
        vector<int> dp(x + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = x; j >= 1; j--) {
                dp[j] = 0;
                for (int k = 1; k <= m && k <= j; k++)
                    dp[j] += dp[j - k];
            }
            dp[0] = 0;
        }
        return dp[x];
    }
};

2)
class Solution {
public:
    int noOfWays(int m, int n, int x) {
        vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= x; j++) {
                for (int k = 1; k <= m && k <= j; k++) {
                    dp[i][j] += dp[i - 1][j - k];
                }
            }
        }
        return dp[n][x];
    }
};

3)
class Solution {
public:
    int solve(int m, int n, int x, vector<vector<int>>& memo) {
        if (x < 0 || n < 0) return 0;
        if (n == 0) return x == 0 ? 1 : 0;
        if (memo[n][x] != -1) return memo[n][x];
        
        int ways = 0;
        for (int face = 1; face <= m; face++) {
            ways += solve(m, n - 1, x - face, memo);
        }
        return memo[n][x] = ways;
    }
    
    int noOfWays(int m, int n, int x) {
        vector<vector<int>> memo(n + 1, vector<int>(x + 1, -1));
        return solve(m, n, x, memo);
    }
};

4)
class Solution {
public:
    int noOfWays(int m, int n, int x) {
        vector<int> dp(x + 1, 0);
        for (int i = 1; i <= min(m, x); i++) dp[i] = 1;
        
        for (int dice = 2; dice <= n; dice++) {
            vector<int> temp(x + 1, 0);
            for (int sum = dice; sum <= x; sum++) {
                for (int face = 1; face <= m && face <= sum; face++) {
                    temp[sum] += dp[sum - face];
                }
            }
            dp = temp;
        }
        return dp[x];
    }
};
