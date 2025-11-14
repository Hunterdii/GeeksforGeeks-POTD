class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1)) return -1;
        vector<int> sum(n + 1);
        for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + stones[i];
        vector<vector<int>> dp(n, vector<int>(n));
        for (int len = k; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for (int mid = i; mid < j; mid += k - 1)
                    dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j]);
                if ((j - i) % (k - 1) == 0)
                    dp[i][j] += sum[j + 1] - sum[i];
            }
        }
        return dp[0][n - 1];
    }
};

2)
class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1)) return -1;
        vector<int> sum(n + 1);
        for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + stones[i];
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, 1e9)));
        for (int i = 0; i < n; i++) dp[i][i][1] = 0;
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                for (int p = 2; p <= k; p++)
                    for (int mid = i; mid < j; mid += k - 1)
                        dp[i][j][p] = min(dp[i][j][p], dp[i][mid][1] + dp[mid + 1][j][p - 1]);
                dp[i][j][1] = dp[i][j][k] + sum[j + 1] - sum[i];
            }
        }
        return dp[0][n - 1][1];
    }
};

3)
class Solution {
    int memo[31][31];
    vector<int> sum;
    int k;
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        k = K;
        if ((n - 1) % (k - 1)) return -1;
        sum.resize(n + 1);
        for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + stones[i];
        memset(memo, -1, sizeof(memo));
        return solve(0, n - 1);
    }
    int solve(int i, int j) {
        if (i == j) return 0;
        if (memo[i][j] != -1) return memo[i][j];
        int res = INT_MAX;
        for (int mid = i; mid < j; mid += k - 1)
            res = min(res, solve(i, mid) + solve(mid + 1, j));
        if ((j - i) % (k - 1) == 0) res += sum[j + 1] - sum[i];
        return memo[i][j] = res;
    }
};
