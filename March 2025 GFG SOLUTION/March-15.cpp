//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        vector<int> dp(sum + 1, INT_MAX);
        dp[0] = 0;
        for (int c : coins) {
            for (int j = c; j <= sum; j++) {
                if (dp[j - c] != INT_MAX) dp[j] = min(dp[j], dp[j - c] + 1);
            }
        }
        return dp[sum] == INT_MAX ? -1 : dp[sum];
    }
};

2)
class Solution {
  public:
    int minCoins(vector<int>& coins, int sum) {
        vector<int> dp(sum + 1, INT_MAX);
        dp[0] = 0;
        for (int c : coins)
            for (int j = c; j <= sum; j++)
                if (dp[j - c] != INT_MAX)
                    dp[j] = min(dp[j], dp[j - c] + 1);
        return dp[sum] == INT_MAX ? -1 : dp[sum];
    }
};

3)
class Solution {
  public:
    vector<vector<int>> dp;
    int solve(vector<int>& coins, int i, int sum) {
        if (sum == 0) return 0;
        if (i < 0 || sum < 0) return INT_MAX;
        if (dp[i][sum] != -1) return dp[i][sum];
        int exclude = solve(coins, i - 1, sum);
        int include = solve(coins, i, sum - coins[i]);
        if (include != INT_MAX) include += 1;
        return dp[i][sum] = min(exclude, include);
    }

    int minCoins(vector<int>& coins, int sum) {
        int n = coins.size();
        dp.assign(n, vector<int>(sum + 1, -1));
        int res = solve(coins, n - 1, sum);
        return res == INT_MAX ? -1 : res;
    }
};


4)
class Solution {
  public:
    int minCoins(vector<int>& coins, int sum) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, INT_MAX));
        for (int i = 0; i <= n; i++) dp[i][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i - 1] && dp[i][j - coins[i - 1]] != INT_MAX)
                    dp[i][j] = min(dp[i][j], dp[i][j - coins[i - 1]] + 1);
            }
        }
        return dp[n][sum] == INT_MAX ? -1 : dp[n][sum];
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
