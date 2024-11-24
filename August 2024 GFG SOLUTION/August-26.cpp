//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int wildCard(string pattern, string str) {
        int m = str.length();
        int n = pattern.length();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int j = 1; j <= n; j++) {
            if (pattern[j - 1] == '*') {
                dp[j] = dp[j - 1];
            }
        }
        for (int i = 1; i <= m; i++) {
            vector<int> newDp(n + 1, 0);
            for (int j = 1; j <= n; j++) {
                if (pattern[j - 1] == '?' || pattern[j - 1] == str[i - 1]) {
                    newDp[j] = dp[j - 1];
                } else if (pattern[j - 1] == '*') {
                    newDp[j] = dp[j] || newDp[j - 1];
                }
            }
            dp.swap(newDp);
        }
        return dp[n];
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends
