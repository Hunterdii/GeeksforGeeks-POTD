class Solution {
public:
    int chocolatePickup(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        function<int(int,int,int)> solve = [&](int i1, int j1, int j2) -> int {
            int i2 = i1 + j1 - j2;
            if (i1 >= n || i2 >= n || j1 >= m || j2 >= m || i2 < 0) return -1e8;
            if (mat[i1][j1] == -1 || mat[i2][j2] == -1) return -1e8;
            if (i1 == n - 1 && j1 == m - 1 && j2 == m - 1) return mat[i1][j1];
            if (dp[i1][j1][j2] != -1) return dp[i1][j1][j2];
            int res = -1e8;
            for (int d1 = 0; d1 < 2; d1++)
                for (int d2 = 0; d2 < 2; d2++)
                    res = max(res, solve(i1 + 1 - d1, j1 + d1, j2 + d2));
            res += mat[i1][j1];
            if (i1 != i2) res += mat[i2][j2];
            return dp[i1][j1][j2] = res;
        };
        return max(0, solve(0, 0, 0));
    }
};

2)
class Solution {
public:
    int chocolatePickup(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, INT_MIN)));
        dp[0][0][0] = mat[0][0];
        for (int i = 0; i < n; i++) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    if (dp[i][j1][j2] == INT_MIN) continue;
                    int i2 = i + j1 - j2;
                    if (i2 < 0 || i2 >= n || mat[i][j1] == -1 || mat[i2][j2] == -1) continue;
                    for (int d1 = 0; d1 < 2; d1++) {
                        for (int d2 = 0; d2 < 2; d2++) {
                            int ni1 = i + 1 - d1, nj1 = j1 + d1;
                            int ni2 = i2 + 1 - d2, nj2 = j2 + d2;
                            if (ni1 >= n || ni2 >= n || nj1 >= m || nj2 >= m) continue;
                            if (mat[ni1][nj1] == -1 || mat[ni2][nj2] == -1) continue;
                            int val = dp[i][j1][j2] + mat[ni1][nj1];
                            if (ni1 != ni2) val += mat[ni2][nj2];
                            dp[ni1][nj1][nj2] = max(dp[ni1][nj1][nj2], val);
                        }
                    }
                }
            }
        }
        return max(0, dp[n - 1][m - 1][m - 1]);
    }
};

3)
class Solution {
public:
    int chocolatePickup(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        map<tuple<int,int,int>, int> dp;
        function<int(int,int,int)> dfs = [&](int i1, int j1, int j2) -> int {
            int i2 = i1 + j1 - j2;
            if (i1 >= n || i2 >= n || i2 < 0 || j1 >= m || j2 >= m) return INT_MIN/2;
            if (mat[i1][j1] == -1 || mat[i2][j2] == -1) return INT_MIN/2;
            if (i1 == n - 1 && j1 == m - 1) return (j2 == m - 1) ? mat[i1][j1] : INT_MIN/2;
            auto key = make_tuple(i1, j1, j2);
            if (dp.count(key)) return dp[key];
            int res = INT_MIN/2;
            for (int d1 = 0; d1 < 2; d1++)
                for (int d2 = 0; d2 < 2; d2++)
                    res = max(res, dfs(i1 + 1 - d1, j1 + d1, j2 + d2));
            if (res > INT_MIN/2) {
                res += mat[i1][j1];
                if (i1 != i2) res += mat[i2][j2];
            }
            return dp[key] = res;
        };
        return max(0, dfs(0, 0, 0));
    }
};

4)
class Solution {
    int n, m;
    int dp[100][100][100];
    int solve(int i1, int j1, int j2, vector<vector<int>>& mat) {
        int i2 = i1 + j1 - j2;
        if (i1 >= n || i2 >= n || i2 < 0 || j1 >= m || j2 >= m) return -1e8;
        if (mat[i1][j1] == -1 || mat[i2][j2] == -1) return -1e8;
        if (i1 == n - 1 && j1 == m - 1 && j2 == m - 1) return mat[i1][j1];
        if (dp[i1][j1][j2] != -1) return dp[i1][j1][j2];
        int res = -1e8;
        for (int d1 = 0; d1 < 2; d1++)
            for (int d2 = 0; d2 < 2; d2++)
                res = max(res, solve(i1 + 1 - d1, j1 + d1, j2 + d2, mat));
        res += mat[i1][j1];
        if (i1 != i2) res += mat[i2][j2];
        return dp[i1][j1][j2] = res;
    }
public:
    int chocolatePickup(vector<vector<int>>& mat) {
        n = mat.size(), m = mat[0].size();
        memset(dp, -1, sizeof(dp));
        return max(0, solve(0, 0, 0, mat));
    }
};
