//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    static const int MOD = 1e9+7;
    long long modexp(long long x, long long y) {
        long long res = 1;
        while (y) {
            if (y & 1) res = res * x % MOD;
            x = x * x % MOD;
            y >>= 1;
        }
        return res;
    }
public:
    int nCr(int n, int r) {
        if (r > n) return 0;
        vector<long long> fact(n+1, 1), inv(n+1);
        for (int i = 1; i <= n; ++i)
            fact[i] = fact[i-1] * i % MOD;
        inv[n] = modexp(fact[n], MOD-2);
        for (int i = n; i > 0; --i)
            inv[i-1] = inv[i] * i % MOD;
        return fact[n] * inv[r] % MOD * inv[n-r] % MOD;
    }
};

2)
class Solution {
public:
    int nCr(int n, int r) {
        if (r > n) return 0;
        const int MOD = 1e9+7;
        vector<vector<int>> C(n+1, vector<int>(r+1, 0));
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= min(i, r); ++j) {
                if (j == 0 || j == i) C[i][j] = 1;
                else C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
            }
        }
        return C[n][r];
    }
};


3)
class Solution {
    static const int MOD = 1e9+7;
    int dp[101][101];
    int solve(int n, int r) {
        if (r == 0 || r == n) return 1;
        if (dp[n][r] != -1) return dp[n][r];
        return dp[n][r] = (solve(n-1, r-1) + solve(n-1, r)) % MOD;
    }
public:
    int nCr(int n, int r) {
        if (r > n) return 0;
        memset(dp, -1, sizeof dp);
        return solve(n, r);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
