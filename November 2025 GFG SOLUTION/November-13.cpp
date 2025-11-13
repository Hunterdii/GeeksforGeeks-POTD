class Solution {
public:
    bool isInterleave(string &s1, string &s2, string &s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        int n = s1.size(), m = s2.size();
        vector<bool> dp(m + 1);
        dp[0] = true;
        for (int j = 1; j <= m; j++) dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];
        for (int i = 1; i <= n; i++) {
            dp[0] = dp[0] && s1[i - 1] == s3[i - 1];
            for (int j = 1; j <= m; j++)
                dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) || (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
        }
        return dp[m];
    }
};

2)
class Solution {
    unordered_map<string, bool> memo;
public:
    bool isInterleave(string &s1, string &s2, string &s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        return solve(s1, s2, s3, 0, 0, 0);
    }
    bool solve(string &s1, string &s2, string &s3, int i, int j, int k) {
        if (k == s3.size()) return i == s1.size() && j == s2.size();
        string key = to_string(i) + "," + to_string(j);
        if (memo.count(key)) return memo[key];
        bool res = false;
        if (i < s1.size() && s1[i] == s3[k]) res = solve(s1, s2, s3, i + 1, j, k + 1);
        if (!res && j < s2.size() && s2[j] == s3[k]) res = solve(s1, s2, s3, i, j + 1, k + 1);
        return memo[key] = res;
    }
};

3)
class Solution {
public:
    bool isInterleave(string &s1, string &s2, string &s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        int n = s1.size(), m = s2.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
        dp[0][0] = true;
        for (int i = 1; i <= n; i++) dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
        for (int j = 1; j <= m; j++) dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
        return dp[n][m];
    }
};
