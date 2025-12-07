class Solution {
public:
    int distinctSubseq(string& str) {
        int n = str.size(), mod = 1e9 + 7, res = 1;
        vector<int> last(26);
        for (int i = 0; i < n; i++) {
            int idx = str[i] - 'a';
            int cur = (2LL * res % mod - last[idx] + mod) % mod;
            last[idx] = res;
            res = cur;
        }
        return res;
    }
};

2)
class Solution {
public:
    int distinctSubseq(string& str) {
        int mod = 1e9 + 7, res = 1;
        unordered_map<char, int> mp;
        for (char c : str) {
            int cur = (2LL * res % mod - mp[c] + mod) % mod;
            mp[c] = res;
            res = cur;
        }
        return res;
    }
};

3)
class Solution {
public:
    int distinctSubseq(string& str) {
        int n = str.size(), mod = 1e9 + 7;
        vector<long long> dp(n + 1);
        dp[0] = 1;
        unordered_map<char, int> last;
        for (int i = 1; i <= n; i++) {
            dp[i] = (2 * dp[i - 1]) % mod;
            if (last.count(str[i - 1]))
                dp[i] = (dp[i] - dp[last[str[i - 1]] - 1] + mod) % mod;
            last[str[i - 1]] = i;
        }
        return dp[n];
    }
};
