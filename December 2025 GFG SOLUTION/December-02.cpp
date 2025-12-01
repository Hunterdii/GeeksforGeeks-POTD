class Solution {
public:
    int maxScore(string &s, vector<vector<char>> &jumps) {
        int n = s.size();
        for (char c = 'a'; c <= 'z'; c++) jumps.push_back({c, c});
        vector<vector<int>> nxt(n, vector<int>(26, -1));
        vector<int> last(26, -1);
        for (int i = n - 1; i >= 0; i--) {
            nxt[i] = last;
            last[s[i] - 'a'] = i;
        }
        vector<vector<int>> ch(26);
        for (auto &j : jumps) ch[j[0] - 'a'].push_back(j[1]);
        vector<int> pre(n + 1);
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + s[i];
        vector<int> dp(n);
        for (int i = n - 2; i >= 0; i--) {
            for (int c : ch[s[i] - 'a']) {
                int j = nxt[i][c - 'a'];
                if (j != -1) dp[i] = max(dp[i], pre[j] - pre[i + (c == s[i])] + dp[j]);
            }
        }
        return dp[0];
    }
};

2)
class Solution {
public:
    int maxScore(string &s, vector<vector<char>> &jumps) {
        int n = s.size();
        map<char, vector<int>> pos;
        for (int i = 0; i < n; i++) pos[s[i]].push_back(i);
        for (char c = 'a'; c <= 'z'; c++) jumps.push_back({c, c});
        unordered_map<char, vector<char>> g;
        for (auto &j : jumps) g[j[0]].push_back(j[1]);
        vector<int> sum(n + 1);
        for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + s[i];
        vector<int> dp(n);
        for (int i = n - 2; i >= 0; i--) {
            for (char c : g[s[i]]) {
                auto &v = pos[c];
                auto it = upper_bound(v.begin(), v.end(), i);
                if (it != v.end()) {
                    int j = *it;
                    dp[i] = max(dp[i], sum[j] - sum[i + (c == s[i])] + dp[j]);
                }
            }
        }
        return dp[0];
    }
};

3)
class Solution {
    vector<int> memo;
    vector<vector<int>> nxt, graph;
    vector<int> sum;
    string str;
    
    int solve(int i) {
        if (i >= str.size() - 1) return 0;
        if (memo[i] != -1) return memo[i];
        int res = 0;
        for (int c : graph[str[i] - 'a']) {
            int j = nxt[i][c - 'a'];
            if (j != -1) res = max(res, sum[j] - sum[i + (c == str[i])] + solve(j));
        }
        return memo[i] = res;
    }
    
public:
    int maxScore(string &s, vector<vector<char>> &jumps) {
        str = s;
        int n = s.size();
        for (char c = 'a'; c <= 'z'; c++) jumps.push_back({c, c});
        nxt.assign(n, vector<int>(26, -1));
        vector<int> last(26, -1);
        for (int i = n - 1; i >= 0; i--) {
            nxt[i] = last;
            last[s[i] - 'a'] = i;
        }
        graph.resize(26);
        for (auto &j : jumps) graph[j[0] - 'a'].push_back(j[1]);
        sum.resize(n + 1);
        for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + s[i];
        memo.assign(n, -1);
        return solve(0);
    }
};

4)
class Solution {
public:
    int maxScore(string &s, vector<vector<char>> &jumps) {
        int n = s.size();
        for (char c = 'a'; c <= 'z'; c++) jumps.push_back({c, c});
        unordered_map<char, vector<char>> adj;
        for (auto &j : jumps) adj[j[0]].push_back(j[1]);
        vector<int> sum(n + 1), dp(n);
        for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + s[i];
        for (int i = n - 2; i >= 0; i--) {
            int mx = 0;
            for (char c : adj[s[i]]) {
                for (int j = i + 1; j < n; j++) {
                    if (s[j] == c) {
                        mx = max(mx, sum[j] - sum[i + (c == s[i])] + dp[j]);
                        break;
                    }
                }
            }
            dp[i] = mx;
        }
        return dp[0];
    }
};
