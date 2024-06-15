//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    vector<vector<int>> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -1}};
    long long dp[4][3][26];
public:
    long long getCount(int n) {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (a[i][j] != -1) {
                    dp[i][j][1] = 1;
                }
            }
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (a[i][j] != -1) {
                        dp[i][j][len] = dp[i][j][len - 1];
                        if (j + 1 < 3 && a[i][j + 1] != -1) {
                            dp[i][j][len] += dp[i][j + 1][len - 1];
                        }
                        if (j - 1 >= 0 && a[i][j - 1] != -1) {
                            dp[i][j][len] += dp[i][j - 1][len - 1];
                        }
                        if (i + 1 < 4 && a[i + 1][j] != -1) {
                            dp[i][j][len] += dp[i + 1][j][len - 1];
                        }
                        if (i - 1 >= 0 && a[i - 1][j] != -1) {
                            dp[i][j][len] += dp[i - 1][j][len - 1];
                        }
                    }
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (a[i][j] != -1) {
                    ans += dp[i][j][n];
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends
