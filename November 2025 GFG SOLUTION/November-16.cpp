class Solution {
public:
    int LCIS(vector<int> &a, vector<int> &b) {
        int m = a.size(), n = b.size(), res = 0;
        vector<int> dp(n, 0);

        for (int i = 0; i < m; i++) {
            int cur = 0;
            for (int j = 0; j < n; j++) {
                if (a[i] == b[j]) {
                    dp[j] = max(dp[j], cur + 1);
                }
                if (b[j] < a[i]) {
                    cur = max(cur, dp[j]);
                }
                res = max(res, dp[j]);
            }
        }
        return res;
    }
};

2)
class Solution {
public:
    int solve(vector<int> &a, vector<int> &b, int i, int j, int last,
              map<tuple<int,int,int>,int> &memo) {
        if (i == a.size() || j == b.size()) return 0;
        auto key = make_tuple(i, j, last);
        if (memo.count(key)) return memo[key];
        int res = max(
            solve(a, b, i + 1, j, last, memo),
            solve(a, b, i, j + 1, last, memo)
        );
        if (a[i] == b[j] && a[i] > last) {
            res = max(res, 1 + solve(a, b, i + 1, j + 1, a[i], memo));
        }
        return memo[key] = res;
    }
    int LCIS(vector<int> &a, vector<int> &b) {
        map<tuple<int,int,int>,int> memo;
        return solve(a, b, 0, 0, INT_MIN, memo);
    }
};

3)
class Solution {
public:
    int LCIS(vector<int> &a, vector<int> &b) {
        int n = b.size(), result = 0;
        vector<int> dp(n, 0);

        for (int x : a) {
            int maxLen = 0;
            for (int j = 0; j < n; j++) {
                if (x == b[j]) {
                    dp[j] = maxLen + 1;
                } else if (b[j] < x) {
                    maxLen = max(maxLen, dp[j]);
                }
                result = max(result, dp[j]);
            }
        }
        return result;
    }
};
