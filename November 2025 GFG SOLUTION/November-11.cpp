class Solution {
public:
    int minSuperSeq(string &s1, string &s2) {
        int m = s1.size(), n = s2.size();
        vector<int> prev(n + 1), curr(n + 1);
        for (int j = 0; j <= n; j++) prev[j] = j;
        for (int i = 1; i <= m; i++) {
            curr[0] = i;
            for (int j = 1; j <= n; j++) {
                curr[j] = (s1[i - 1] == s2[j - 1]) ? 1 + prev[j - 1] : 
                          1 + min(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return prev[n];
    }
};

2)
class Solution {
public:
    int minSuperSeq(string &s1, string &s2) {
        int m = s1.size(), n = s2.size();
        vector<int> prev(n + 1, 0), curr(n + 1, 0);
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return m + n - prev[n];
    }
};

3)
class Solution {
public:
    int minSuperSeq(string &s1, string &s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int j = 0; j <= n; j++) dp[0][j] = j;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};

4)
class Solution {
public:
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>>& memo) {
        if (i == s1.size()) return s2.size() - j;
        if (j == s2.size()) return s1.size() - i;
        if (memo[i][j] != -1) return memo[i][j];
        if (s1[i] == s2[j])
            return memo[i][j] = 1 + solve(i + 1, j + 1, s1, s2, memo);
        return memo[i][j] = 1 + min(solve(i + 1, j, s1, s2, memo), 
                                     solve(i, j + 1, s1, s2, memo));
    }
    int minSuperSeq(string &s1, string &s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return solve(0, 0, s1, s2, memo);
    }
};
