//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countWays(string &s) {
        if (s[0] == '0') return 0;
        int n = s.size(), prev2 = 1, prev1 = 1;
        for (int i = 1; i < n; i++) {
            int curr = 0;
            if (s[i] != '0') curr = prev1;
            int num = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (num >= 10 && num <= 26) curr += prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

2)
class Solution {
public:
    int countWays(string &s) {
        if (s[0] == '0') return 0;
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;

        for (int i = 1; i < n; i++) {
            if (s[i] != '0') dp[i + 1] = dp[i];
            int num = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (num >= 10 && num <= 26) dp[i + 1] += dp[i - 1];
        }
        return dp[n];
    }
};


3)
class Solution {
public:
    int helper(string &s, int i, vector<int>& dp) {
        if (i == s.size()) return 1;
        if (s[i] == '0') return 0;
        if (dp[i] != -1) return dp[i];

        int ans = helper(s, i + 1, dp);
        if (i < s.size() - 1) {
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (num >= 10 && num <= 26) ans += helper(s, i + 2, dp);
        }
        return dp[i] = ans;
    }

    int countWays(string &s) {
        vector<int> dp(s.size(), -1);
        return helper(s, 0, dp);
    }
};




//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
