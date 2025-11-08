class Solution {
public:
    int maxProfit(vector<vector<int>> &jobs) {
        sort(jobs.begin(), jobs.end());
        int n = jobs.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int l = i + 1, r = n - 1, nxt = n;
            while (l <= r) {
                int m = (l + r) / 2;
                if (jobs[m][0] >= jobs[i][1]) {
                    nxt = m;
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            dp[i] = max(jobs[i][2] + dp[nxt], dp[i + 1]);
        }
        return dp[0];
    }
};

2)
class Solution {
public:
    int maxProfit(vector<vector<int>> &jobs) {
        sort(jobs.begin(), jobs.end());
        int n = jobs.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            auto it = lower_bound(jobs.begin() + i + 1, jobs.end(), jobs[i][1], 
                [](const vector<int>& job, int val) { return job[0] < val; });
            int nxt = it - jobs.begin();
            dp[i] = max(jobs[i][2] + dp[nxt], dp[i + 1]);
        }
        return dp[0];
    }
};

3)
class Solution {
public:
    int maxProfit(vector<vector<int>> &jobs) {
        sort(jobs.begin(), jobs.end());
        vector<int> memo(jobs.size(), -1);
        return solve(jobs, 0, memo);
    }
    int solve(vector<vector<int>> &jobs, int i, vector<int> &memo) {
        if (i >= jobs.size()) return 0;
        if (memo[i] != -1) return memo[i];
        int l = i + 1, r = jobs.size() - 1, nxt = jobs.size();
        while (l <= r) {
            int m = (l + r) / 2;
            if (jobs[m][0] >= jobs[i][1]) {
                nxt = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return memo[i] = max(jobs[i][2] + solve(jobs, nxt, memo), solve(jobs, i + 1, memo));
    }
};

4)
class Solution {
public:
    int maxProfit(vector<vector<int>> &jobs) {
        sort(jobs.begin(), jobs.end(), [](auto &a, auto &b) { return a[1] < b[1]; });
        int n = jobs.size();
        vector<int> dp(n);
        dp[0] = jobs[0][2];
        for (int i = 1; i < n; i++) {
            int profit = jobs[i][2];
            int l = 0, r = i - 1, last = -1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (jobs[m][1] <= jobs[i][0]) {
                    last = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            if (last != -1) profit += dp[last];
            dp[i] = max(dp[i - 1], profit);
        }
        return dp[n - 1];
    }
};
