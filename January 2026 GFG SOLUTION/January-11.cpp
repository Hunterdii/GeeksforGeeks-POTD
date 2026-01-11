class Solution {
public:
    string minWindow(string& s1, string& s2) {
        int m = s1.size(), n = s2.size();
        int start = -1, minLen = INT_MAX;
        for (int i = 0, j = 0; i < m; i++) {
            if (s1[i] == s2[j]) j++;
            if (j == n) {
                int end = i;
                j--;
                while (j >= 0) {
                    if (s1[i] == s2[j]) j--;
                    i--;
                }
                i++;
                j++;
                if (end - i + 1 < minLen) {
                    minLen = end - i + 1;
                    start = i;
                }
            }
        }
        return start == -1 ? "" : s1.substr(start, minLen);
    }
}; 

2)
class Solution {
public:
    string minWindow(string& s1, string& s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            if (s1[i] == s2[0]) dp[i][0] = i;
            else if (i > 0) dp[i][0] = dp[i-1][0];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (s1[i] == s2[j]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = dp[i-1][j];
            }
        }
        int start = -1, minLen = INT_MAX;
        for (int i = 0; i < m; i++) {
            if (dp[i][n-1] != -1) {
                int len = i - dp[i][n-1] + 1;
                if (len < minLen) {
                    minLen = len;
                    start = dp[i][n-1];
                }
            }
        }
        return start == -1 ? "" : s1.substr(start, minLen);
    }
};

3)
class Solution {
public:
    string minWindow(string& s1, string& s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> next(m+1, vector<int>(26, -1));
        for (int i = m-1; i >= 0; i--) {
            next[i] = next[i+1];
            next[i][s1[i]-'a'] = i;
        }
        int start = -1, minLen = INT_MAX;
        for (int i = 0; i < m; i++) {
            int pos = i, j = 0;
            while (j < n && pos < m) {
                pos = next[pos][s2[j]-'a'];
                if (pos == -1) break;
                j++;
                if (j < n) pos++;
            }
            if (j == n) {
                int len = pos - i + 1;
                if (len < minLen) {
                    minLen = len;
                    start = i;
                }
            }
        }
        return start == -1 ? "" : s1.substr(start, minLen);
    }
};

4)
class Solution {
public:
    string minWindow(string& s1, string& s2) {
        int m = s1.size(), n = s2.size();
        int start = -1, minLen = INT_MAX;
        int i = 0, j = 0;
        while (i < m) {
            if (s1[i] == s2[j]) {
                j++;
                if (j == n) {
                    int end = i;
                    j--;
                    while (j >= 0) {
                        if (s1[i] == s2[j]) j--;
                        i--;
                    }
                    i++;
                    if (end - i + 1 < minLen) {
                        minLen = end - i + 1;
                        start = i;
                    }
                    j = 0;
                }
            }
            i++;
        }
        return start == -1 ? "" : s1.substr(start, minLen);
    }
};
