//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int countWays(string s1, string s2) {
        int n = s1.length(), m = s2.length();

        vector<int> dp(m + 1, 0);
        int mod = 1e9 + 7;
        dp[0] = 1; 

        for (int i = 1; i <= n; i++) {
            int prev = dp[0];
            for (int j = 1; j <= m; j++) {
                int temp = dp[j]; 
                if (s1[i - 1] == s2[j - 1]) {
                    dp[j] = (prev + dp[j]) % mod;
                }
                prev = temp; 
            }
        }
        return dp[m] % mod;
    }
};
//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends
