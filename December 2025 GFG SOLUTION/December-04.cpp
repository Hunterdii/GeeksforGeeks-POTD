class Solution {
public:
    int minCost(vector<int> &keys, vector<int> &freq) {
        int n = keys.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> ps(n + 1, 0);
        for (int i = 0; i < n; i++) ps[i + 1] = ps[i] + freq[i];
        for (int i = 0; i < n; i++) dp[i][i] = freq[i];
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                dp[i][j] = INT_MAX;
                int fsum = ps[j + 1] - ps[i];
                for (int r = i; r <= j; r++) {
                    int c = (r > i ? dp[i][r - 1] : 0) + (r < j ? dp[r + 1][j] : 0) + fsum;
                    dp[i][j] = min(dp[i][j], c);
                }
            }
        }
        return dp[0][n - 1];
    }
};

2)
class Solution {
public:
    int minCost(vector<int> &keys, vector<int> &freq) {
        int n = keys.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return solve(0, n - 1, freq, memo);
    }
    int solve(int i, int j, vector<int>& f, vector<vector<int>>& m) {
        if (i > j) return 0;
        if (m[i][j] != -1) return m[i][j];
        int fs = 0;
        for (int k = i; k <= j; k++) fs += f[k];
        int res = INT_MAX;
        for (int r = i; r <= j; r++) {
            int c = solve(i, r - 1, f, m) + solve(r + 1, j, f, m) + fs;
            res = min(res, c);
        }
        return m[i][j] = res;
    }
};

3)
class Solution {
public:
    int minCost(vector<int> &keys, vector<int> &freq) {
        int n = keys.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int g = 0; g < n; g++) {
            for (int i = 0, j = g; j < n; i++, j++) {
                if (g == 0) dp[i][j] = freq[i];
                else {
                    int mn = INT_MAX, sm = 0;
                    for (int k = i; k <= j; k++) sm += freq[k];
                    for (int r = i; r <= j; r++) {
                        int lt = r > i ? dp[i][r - 1] : 0;
                        int rt = r < j ? dp[r + 1][j] : 0;
                        mn = min(mn, lt + rt);
                    }
                    dp[i][j] = mn + sm;
                }
            }
        }
        return dp[0][n - 1];
    }
};

4)
class Solution {
public:
    int minCost(vector<int> &keys, vector<int> &freq) {
        int n = keys.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        vector<vector<int>> rt(n + 1, vector<int>(n + 1, 0));
        vector<int> ps(n + 1, 0);
        for (int i = 0; i < n; i++) {
            ps[i + 1] = ps[i] + freq[i];
            dp[i][i] = freq[i];
            rt[i][i] = i;
        }
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                dp[i][j] = INT_MAX;
                for (int r = rt[i][j - 1]; r <= rt[i + 1][j]; r++) {
                    int c = (r > i ? dp[i][r - 1] : 0) + (r < j ? dp[r + 1][j] : 0) + ps[j + 1] - ps[i];
                    if (c < dp[i][j]) {
                        dp[i][j] = c;
                        rt[i][j] = r;
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};
