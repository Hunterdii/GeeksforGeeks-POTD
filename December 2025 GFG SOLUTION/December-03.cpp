class Solution {
public:
    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        if (n <= 1) return n ? cost[0][0] : 0;
        int FULL = (1 << n) - 1;
        vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));
        dp[1][0] = 0;
        for (int mask = 1; mask <= FULL; mask++) {
            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i)) || dp[mask][i] == INT_MAX) continue;
                for (int j = 0; j < n; j++) {
                    if (mask & (1 << j)) continue;
                    int nxt = mask | (1 << j);
                    dp[nxt][j] = min(dp[nxt][j], dp[mask][i] + cost[i][j]);
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
            if (dp[FULL][i] != INT_MAX)
                ans = min(ans, dp[FULL][i] + cost[i][0]);
        return ans;
    }
};

2)
class Solution {
public:
    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        if (n <= 1) return n ? cost[0][0] : 0;
        vector<vector<int>> memo(1 << n, vector<int>(n, -1));
        function<int(int, int)> solve = [&](int mask, int pos) {
            if (mask == (1 << n) - 1) return cost[pos][0];
            if (memo[mask][pos] != -1) return memo[mask][pos];
            int res = INT_MAX;
            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i))) {
                    res = min(res, cost[pos][i] + solve(mask | (1 << i), i));
                }
            }
            return memo[mask][pos] = res;
        };
        return solve(1, 0);
    }
};

3)
class Solution {
public:
    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        if (n <= 1) return n ? cost[0][0] : 0;
        vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));
        vector<vector<int>> parent(1 << n, vector<int>(n, -1));
        dp[1][0] = 0;
        for (int mask = 1; mask < (1 << n); mask++) {
            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i)) || dp[mask][i] == INT_MAX) continue;
                for (int j = 0; j < n; j++) {
                    if (mask & (1 << j)) continue;
                    int nxt = mask | (1 << j);
                    if (dp[nxt][j] > dp[mask][i] + cost[i][j]) {
                        dp[nxt][j] = dp[mask][i] + cost[i][j];
                        parent[nxt][j] = i;
                    }
                }
            }
        }
        int ans = INT_MAX, lastCity = -1;
        for (int i = 0; i < n; i++) {
            if (dp[(1 << n) - 1][i] != INT_MAX && ans > dp[(1 << n) - 1][i] + cost[i][0]) {
                ans = dp[(1 << n) - 1][i] + cost[i][0];
                lastCity = i;
            }
        }
        return ans;
    }
};

4)
class Solution {
public:
    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        if (n <= 1) return n ? cost[0][0] : 0;
        map<pair<int,int>, int> curr, next;
        curr[{1, 0}] = 0;
        for (int cnt = 1; cnt < n; cnt++) {
            next.clear();
            for (auto& [key, val] : curr) {
                int mask = key.first, pos = key.second;
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) continue;
                    int nmask = mask | (1 << i);
                    if (!next.count({nmask, i}) || next[{nmask, i}] > val + cost[pos][i])
                        next[{nmask, i}] = val + cost[pos][i];
                }
            }
            curr = next;
        }
        int ans = INT_MAX;
        for (auto& [key, val] : curr)
            ans = min(ans, val + cost[key.second][0]);
        return ans;
    }
};
