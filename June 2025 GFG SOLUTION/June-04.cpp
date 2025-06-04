class Solution {
  public:
    int lcsOf3(string& s1, string& s2, string& s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        vector<vector<int>> prev(n2 + 1, vector<int>(n3 + 1, 0));
        vector<vector<int>> curr(n2 + 1, vector<int>(n3 + 1, 0));
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                for (int k = 1; k <= n3; ++k) {
                    if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1])
                        curr[j][k] = 1 + prev[j - 1][k - 1];
                    else
                        curr[j][k] = max({prev[j][k], curr[j - 1][k], curr[j][k - 1]});
                }
            }
            prev.swap(curr);
        }
        return prev[n2][n3];
    }
};

2)
class Solution {
  public:
    int lcsOf3(string& s1, string& s2, string& s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        vector<vector<vector<int>>> dp(
            n1 + 1,
            vector<vector<int>>(n2 + 1, vector<int>(n3 + 1, 0))
        );
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                for (int k = 1; k <= n3; ++k) {
                    if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1])
                        dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                    else
                        dp[i][j][k] = max({
                            dp[i - 1][j][k],
                            dp[i][j - 1][k],
                            dp[i][j][k - 1]
                        });
                }
            }
        }
        return dp[n1][n2][n3];
    }
};

3)
class Solution {
  public:
    int dp[101][101][101]; 

    int solve(int i, int j, int k, const string& s1, const string& s2, const string& s3) {
        if (i < 0 || j < 0 || k < 0) return 0;
        if (dp[i][j][k] != -1) return dp[i][j][k];
        if (s1[i] == s2[j] && s2[j] == s3[k])
            return dp[i][j][k] = 1 + solve(i - 1, j - 1, k - 1, s1, s2, s3);
        return dp[i][j][k] = max({
            solve(i - 1, j, k, s1, s2, s3),
            solve(i, j - 1, k, s1, s2, s3),
            solve(i, j, k - 1, s1, s2, s3)
        });
    }

    int lcsOf3(string& s1, string& s2, string& s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        memset(dp, -1, sizeof(dp));
        return solve(n1 - 1, n2 - 1, n3 - 1, s1, s2, s3);
    }
};
