//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
public:
    int longestPalinSubseq(string &s) {
        int n = s.size();
        vector<int> prev(n + 1, 0), curr(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == s[n - j]) 
                    curr[j] = 1 + prev[j - 1];
                else 
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            swap(prev, curr);
        }
        return prev[n];
    }
};


2)
class Solution {
public:
    int longestPalinSubseq(string &s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) 
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                else 
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};


3)
class Solution {
public:
    int helper(string &s, int i, int j, vector<vector<int>> &dp) {
        if (i > j) return 0;
        if (i == j) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == s[j]) 
            return dp[i][j] = 2 + helper(s, i + 1, j - 1, dp);
        return dp[i][j] = max(helper(s, i + 1, j, dp), helper(s, i, j - 1, dp));
    }

    int longestPalinSubseq(string &s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(s, 0, n - 1, dp);
    }
};



//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends
