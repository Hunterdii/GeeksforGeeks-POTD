class Solution {
  public:
    int minDeletions(string &s) {
        int n = s.size();
        vector<int> dp(n), prev(n);
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = 1;
            for (int j = i + 1; j < n; ++j)
                dp[j] = s[i] == s[j] ? prev[j - 1] + 2 : max(prev[j], dp[j - 1]);
            prev = dp;
        }
        return n - dp[n - 1];
    }
};

2)
class Solution {
  public:
    int minDeletions(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dp[i][j] = s[i - 1] == t[j - 1] ? 1 + dp[i - 1][j - 1] : max(dp[i - 1][j], dp[i][j - 1]);
        return n - dp[n][n];
    }
};

3)
class Solution {
  public:
    int minDeletions(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        vector<int> prev(n + 1), curr(n + 1);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j)
                curr[j] = s[i - 1] == t[j - 1] ? 1 + prev[j - 1] : max(prev[j], curr[j - 1]);
            swap(prev, curr);
        }
        return n - prev[n];
    }
};
