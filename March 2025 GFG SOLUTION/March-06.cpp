//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int lcs(string &s1, string &s2) {
        int n = s1.size(), m = s2.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                curr[j] = s1[i - 1] == s2[j - 1] ? prev[j - 1] + 1 : max(prev[j], curr[j - 1]);
            }
            swap(prev, curr);
        }
        return prev[m];
    }
};

2)
class Solution {
public:
    int lcs(string &s1, string &s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return helper(s1, s2, n, m, dp);
    }
    int helper(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
        if (i == 0 || j == 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (s1[i - 1] == s2[j - 1]) 
            return dp[i][j] = 1 + helper(s1, s2, i - 1, j - 1, dp);
        return dp[i][j] = max(helper(s1, s2, i - 1, j, dp), helper(s1, s2, i, j - 1, dp));
    }
};



3)
class Solution {
public:
    int lcs(string &s1, string &s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends
