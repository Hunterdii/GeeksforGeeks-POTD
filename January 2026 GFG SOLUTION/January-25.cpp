class Solution {
public:
    int findWays(int n) {
        if (n & 1) return 0;
        n >>= 1;
        long long res = 1;
        for (int i = 0; i < n; i++) {
            res = res * (2 * n - i) / (i + 1);
        }
        return res / (n + 1);
    }
};

2)
class Solution {
public:
    int findWays(int n) {
        if (n & 1) return 0;
        n >>= 1;
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
        return dp[n];
    }
};

3)
class Solution {
public:
    int findWays(int n) {
        if (n & 1) return 0;
        n >>= 1;
        long long res = 1;
        for (int i = 1; i <= n; i++) {
            res = res * (n + i) / i;
        }
        return res / (n + 1);
    }
};

4)
class Solution {
public:
    unordered_map<int, long long> memo;
    
    long long catalan(int n) {
        if (n <= 1) return 1;
        if (memo.count(n)) return memo[n];
        long long res = 0;
        for (int i = 0; i < n; i++) {
            res += catalan(i) * catalan(n - 1 - i);
        }
        return memo[n] = res;
    }
    
    int findWays(int n) {
        if (n & 1) return 0;
        return catalan(n >> 1);
    }
};
