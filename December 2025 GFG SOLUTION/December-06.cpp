class Solution {
public:
    int maximumAmount(vector<int>& arr) {
        int n = arr.size(), s = 0;
        vector<int> dp(n);
        for (int i = n - 1; i >= 0; i--) {
            s += arr[i];
            for (int j = i; j < n; j++)
                dp[j] = (i == j) ? arr[j] : max(arr[i] - dp[j], arr[j] - dp[j - 1]);
        }
        return (s + dp[n - 1]) / 2;
    }
};

2)
class Solution {
public:
    int maximumAmount(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n));
        int s = 0;
        for (int i = 0; i < n; i++) {
            dp[i][i] = arr[i];
            s += arr[i];
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                dp[i][j] = max(arr[i] - dp[i + 1][j], arr[j] - dp[i][j - 1]);
            }
        }
        return (s + dp[0][n - 1]) / 2;
    }
};

3)
class Solution {
    map<pair<int,int>, int> memo;
    int solve(vector<int>& arr, int l, int r) {
        if (l == r) return arr[l];
        if (l > r) return 0;
        auto key = make_pair(l, r);
        if (memo.count(key)) return memo[key];
        return memo[key] = max(arr[l] - solve(arr, l + 1, r), 
                                arr[r] - solve(arr, l, r - 1));
    }
public:
    int maximumAmount(vector<int>& arr) {
        int s = accumulate(arr.begin(), arr.end(), 0);
        return (s + solve(arr, 0, arr.size() - 1)) / 2;
    }
};

4)
class Solution {
public:
    int maximumAmount(vector<int>& arr) {
        int n = arr.size(), s = accumulate(arr.begin(), arr.end(), 0);
        vector<int> cur(n), pre(n);
        for (int i = 0; i < n; i++) cur[i] = arr[i];
        for (int len = 2; len <= n; len++) {
            swap(cur, pre);
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                cur[i] = max(arr[i] - pre[i + 1], arr[j] - pre[i]);
            }
        }
        return (s + cur[0]) / 2;
    }
};
