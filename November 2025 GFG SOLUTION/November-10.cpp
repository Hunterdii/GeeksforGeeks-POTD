class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;
        int buy = -arr[0], sell = 0, cooldown = 0;
        for (int i = 1; i < n; i++) {
            int prevBuy = buy, prevSell = sell;
            buy = max(buy, cooldown - arr[i]);
            sell = max(sell, prevBuy + arr[i]);
            cooldown = max(cooldown, prevSell);
        }
        return max(sell, cooldown);
    }
};

2)
class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;
        vector<int> hold(n), sold(n), rest(n);
        hold[0] = -arr[0];
        for (int i = 1; i < n; i++) {
            hold[i] = max(hold[i-1], rest[i-1] - arr[i]);
            sold[i] = hold[i-1] + arr[i];
            rest[i] = max(rest[i-1], sold[i-1]);
        }
        return max(sold[n-1], rest[n-1]);
    }
};

3)
class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -arr[0];
        if (n > 1) {
            dp[1][0] = max(0, arr[1] - arr[0]);
            dp[1][1] = max(-arr[0], -arr[1]);
        }
        for (int i = 2; i < n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + arr[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-2][0] - arr[i]);
        }
        return dp[n-1][0];
    }
};

4)
class Solution {
public:
    int solve(int i, int canBuy, vector<int>& arr, map<pair<int,int>,int>& memo) {
        if (i >= arr.size()) return 0;
        if (memo.count({i, canBuy})) return memo[{i, canBuy}];
        int profit = 0;
        if (canBuy) {
            profit = max(-arr[i] + solve(i+1, 0, arr, memo), solve(i+1, 1, arr, memo));
        } else {
            profit = max(arr[i] + solve(i+2, 1, arr, memo), solve(i+1, 0, arr, memo));
        }
        return memo[{i, canBuy}] = profit;
    }
    int maxProfit(vector<int>& arr) {
        map<pair<int,int>,int> memo;
        return solve(0, 1, arr, memo);
    }
};
