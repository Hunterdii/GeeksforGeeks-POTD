class Solution {
public:
    bool wildCard(string &txt, string &pat) {
        int n = txt.size(), m = pat.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int j = 1; j <= m; j++) 
            if (pat[j - 1] == '*') dp[0][j] = dp[0][j - 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (pat[j - 1] == '*') 
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                else if (pat[j - 1] == '?' || txt[i - 1] == pat[j - 1]) 
                    dp[i][j] = dp[i - 1][j - 1];
            }
        }
        return dp[n][m];
    }
};

2)
class Solution {
public:
    bool wildCard(string &txt, string &pat) {
        int n = txt.size(), m = pat.size();
        vector<bool> prev(m + 1, false), curr(m + 1, false);
        prev[0] = true;
        for (int j = 1; j <= m; j++) 
            if (pat[j - 1] == '*') prev[j] = prev[j - 1];
        for (int i = 1; i <= n; i++) {
            curr[0] = false;
            for (int j = 1; j <= m; j++) {
                if (pat[j - 1] == '*') 
                    curr[j] = curr[j - 1] || prev[j];
                else if (pat[j - 1] == '?' || txt[i - 1] == pat[j - 1]) 
                    curr[j] = prev[j - 1];
                else curr[j] = false;
            }
            swap(prev, curr);
        }
        return prev[m];
    }
};

3)
class Solution {
public:
    bool wildCard(string &txt, string &pat) {
        int n = txt.size(), m = pat.size();
        int i = 0, j = 0, star = -1, match = 0;
        while (i < n) {
            if (j < m && (pat[j] == '?' || txt[i] == pat[j])) {
                i++; j++;
            } else if (j < m && pat[j] == '*') {
                star = j++; match = i;
            } else if (star != -1) {
                j = star + 1; i = ++match;
            } else return false;
        }
        while (j < m && pat[j] == '*') j++;
        return j == m;
    }
};

4)
class Solution {
public:
    bool solve(string &txt, string &pat, int i, int j, vector<vector<int>> &dp) {
        if (j == 0) return i == 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (i == 0) {
            for (int k = 0; k < j; k++) 
                if (pat[k] != '*') return dp[i][j] = 0;
            return dp[i][j] = 1;
        }
        if (txt[i - 1] == pat[j - 1] || pat[j - 1] == '?')
            return dp[i][j] = solve(txt, pat, i - 1, j - 1, dp);
        if (pat[j - 1] == '*')
            return dp[i][j] = solve(txt, pat, i, j - 1, dp) || solve(txt, pat, i - 1, j, dp);
        return dp[i][j] = 0;
    }
    bool wildCard(string &txt, string &pat) {
        int n = txt.size(), m = pat.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(txt, pat, n, m, dp);
    }
};
