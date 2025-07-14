class Solution {
public:
    int cuts(string s) {
        if (s[0] == '0') return -1;
        int n = s.size();
        unordered_set<long long> powers;
        for (long long p = 1; p <= 1e9; p *= 5) powers.insert(p);
        vector<int> dp(n + 1, n + 1);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') continue;
            long long num = 0;
            for (int j = i; j < n && num <= 1e9; ++j) {
                num = (num << 1) + (s[j] & 1);
                if (powers.count(num) && dp[j + 1] < n + 1)
                    dp[i] = min(dp[i], 1 + dp[j + 1]);
            }
        }
        return dp[0] > n ? -1 : dp[0];
    }
};


2)
class Solution {
public:
    int cuts(string s) {
        if (s[0] == '0') return -1;
        int n = s.size();
        unordered_set<long long> pow5;
        for (long long p = 1; p <= 1e9; p *= 5) pow5.insert(p);
        queue<int> q;
        vector<bool> vis(n + 1, false);
        q.push(0);
        vis[0] = true;
        int level = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int t = 0; t < sz; ++t) {
                int pos = q.front();
                q.pop();
                if (pos == n) return level;
                if (s[pos] == '0') continue;
                long long num = 0;
                for (int i = pos; i < n && num <= 1e9; ++i) {
                    num = (num << 1) + (s[i] & 1);
                    if (pow5.count(num) && !vis[i + 1]) {
                        vis[i + 1] = true;
                        q.push(i + 1);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};


3)
class Solution {
public:
    int cuts(string s) {
        if (s[0] == '0') return -1;
        unordered_set<long long> p5;
        for (long long x = 1; x <= 1e9; x *= 5) p5.insert(x);
        unordered_map<int, int> memo;
        function<int(int)> solve = [&](int pos) -> int {
            if (pos == s.size()) return 0;
            if (memo.count(pos)) return memo[pos];
            if (s[pos] == '0') return memo[pos] = 1e9;
            int res = 1e9;
            long long num = 0;
            for (int i = pos; i < s.size() && num <= 1e9; ++i) {
                num = (num << 1) + (s[i] & 1);
                if (p5.count(num)) {
                    int next = solve(i + 1);
                    if (next < 1e9) res = min(res, 1 + next);
                }
            }
            return memo[pos] = res;
        };
        int ans = solve(0);
        return ans >= 1e9 ? -1 : ans;
    }
};
