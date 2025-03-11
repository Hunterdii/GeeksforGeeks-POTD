//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    long long countWays(int n) {
        long long a = 1, b = 1;
        for (int i = 2; i <= n; i++) 
            tie(a, b) = make_tuple(b, a + b);
        return b;
    }
};

2)
class Solution {
public:
    long long countWays(int n) {
        long long a = 1, b = 1;
        while (n-- > 1) b += a, a = b - a;
        return b;
    }
};

3)
class Solution {
public:
    long long countWays(int n) {
        vector<long long> dp(n + 1, 1);
        for (int i = 2; i <= n; i++) 
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};

4)
class Solution {
public:
    void multiply(long long F[2][2], long long M[2][2]) {
        long long x = F[0][0]*M[0][0] + F[0][1]*M[1][0];
        long long y = F[0][0]*M[0][1] + F[0][1]*M[1][1];
        long long z = F[1][0]*M[0][0] + F[1][1]*M[1][0];
        long long w = F[1][0]*M[0][1] + F[1][1]*M[1][1];
        F[0][0] = x; F[0][1] = y;
        F[1][0] = z; F[1][1] = w;
    }

    void power(long long F[2][2], int n) {
        if (n <= 1) return;
        long long M[2][2] = {{1, 1}, {1, 0}};
        power(F, n / 2);
        multiply(F, F);
        if (n % 2 != 0) multiply(F, M);
    }

    long long countWays(int n) {
        if (n == 0) return 1;
        long long F[2][2] = {{1, 1}, {1, 0}};
        power(F, n);
        return F[0][0];
    }
};


5)
class Solution {
public:
    vector<long long> dp;
    long long countWays(int n) {
        if (dp.empty()) dp.resize(n + 1, -1);
        if (n <= 1) return 1;
        if (dp[n] != -1) return dp[n];
        return dp[n] = countWays(n - 1) + countWays(n - 2);
    }
};

//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
