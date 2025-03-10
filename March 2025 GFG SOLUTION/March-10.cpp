//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int editDistance(string& s1, string& s2) {
        int n = s1.size(), m = s2.size();
        vector<int> dp(m + 1);
        iota(dp.begin(), dp.end(), 0);
        for (int i = 1; i <= n; ++i) {
            int prev = dp[0];
            dp[0] = i;
            for (int j = 1; j <= m; ++j) {
                int temp = dp[j];
                dp[j] = s1[i - 1] == s2[j - 1] ? prev : 1 + min({prev, dp[j - 1], dp[j]});
                prev = temp;
            }
        }
        return dp[m];
    }
};



2)
class Solution {
public:
    int editDistance(string& s1, string& s2) {
        int m = s1.size(), n = s2.size();
        vector<int> prev(n + 1), curr(n + 1);
        iota(prev.begin(), prev.end(), 0);
        for (int i = 1; i <= m; i++) {
            curr[0] = i;
            for (int j = 1; j <= n; j++)
                curr[j] = s1[i-1] == s2[j-1] ? prev[j-1] : 1 + min({prev[j-1], prev[j], curr[j-1]});
            swap(prev, curr);
        }
        return prev[n];
    }
};

3)
class Solution {
public:
    int editDistance(string& s1, string& s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int j = 0; j <= n; j++) dp[0][j] = j;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
            }
        }
        return dp[m][n];
    }
};



//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
