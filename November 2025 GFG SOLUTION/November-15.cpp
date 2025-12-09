class Solution {
public:
    int minCutCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int sz = cuts.size();
        vector<vector<int>> dp(sz, vector<int>(sz, 0));
        for (int gap = 2; gap < sz; gap++) {
            for (int i = 0; i + gap < sz; i++) {
                int j = i + gap;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);
                }
            }
        }
        return dp[0][sz - 1];
    }
};

2)
class Solution {
public:
    int minCutCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> memo(cuts.size(), vector<int>(cuts.size(), -1));
        return solve(0, cuts.size() - 1, cuts, memo);
    }
    int solve(int i, int j, vector<int>& c, vector<vector<int>>& m) {
        if (j - i <= 1) return 0;
        if (m[i][j] != -1) return m[i][j];
        int res = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            res = min(res, solve(i, k, c, m) + solve(k, j, c, m) + c[j] - c[i]);
        }
        return m[i][j] = res;
    }
};

3)
class Solution {
public:
    int minCutCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        unordered_map<int, int> dp;
        return dfs(0, cuts.size() - 1, cuts, dp);
    }
    int dfs(int l, int r, vector<int>& c, unordered_map<int, int>& dp) {
        if (r - l <= 1) return 0;
        int key = l * 1000 + r;
        if (dp.count(key)) return dp[key];
        int ans = INT_MAX;
        for (int i = l + 1; i < r; i++) {
            ans = min(ans, dfs(l, i, c, dp) + dfs(i, r, c, dp) + c[r] - c[l]);
        }
        return dp[key] = ans;
    }
};
